//
// Created by barbarin on 23/02/18.
//

#include <iostream>

#include "SchedulerTask.hpp"

/* *************************************************************************************************************
 * Periodic Task class
 * ************************************************************************************************************/

/**
 * @brief Constructor for exec system with life. For example if we would like to do N photo with camera all
 * 1300 ms. Can execute multiple task in order by Scheduler
 *
 * @param ioService task order from PeriodicScheduler
 * @param task function we want to call
 * @param interval_ms time after recall task while nCall
 * @param nCall number of call
 */
PeriodicTask::PeriodicTask(boost::asio::io_service &ioService, handler task, long interval_ms, int32_t nCall) :
_ioService(ioService),
_interval(interval_ms),
_task(task),
_timer(ioService),
_nCall(nCall) {

    // Start ioService with first execute
    _ioService.post(std::bind(&PeriodicTask::exec, this));

};

/**
 * @brief Constructor for exec system with timeout. Recall task if not true while timeout is not done. Can execute multiple
 * task in order by scheduler
 *
 * @param ioService task order from PeriodicScheduler
 * @param task function we want to call
 * @param interval_ms time after we stop to recall task
 * @param info data string for specify call location in case of Timeout error
 */
PeriodicTask::PeriodicTask(boost::asio::io_service &ioService, handler task, long interval_ms, const std::string &info) :
_ioService(ioService),
_task(task),
_interval(interval_ms),
_timer(ioService),
_info(info) {

    // Start ioService by timeout
    _ioService.post(std::bind(&PeriodicTask::execWhile, this));

}

PeriodicTask::~PeriodicTask() {
    _ioService.reset();
}

/**
 * @brief Call and recall task when nCall is > 0 or infinity call if nCall < 0
 */
void PeriodicTask::exec() {

    if (_nCall == stateTask::NONSTOP || _nCall != stateTask::DONE) {

        try {
            // Start task
            _task();

            // Reduce task
            --_nCall;

        } catch (const std::exception &except) {

            std::cerr << "Error function Scheduler Execute : " << except.what() << std::endl;
            // Rethrow exactly exception
            throw ;

        }

        _timer.expires_at(_timer.expires_at() + boost::posix_time::millisec(_interval));

        _timer.async_wait(std::bind(&PeriodicTask::exec, this));
    }
}

/**
 * @brief Call and recall task when timeout isnt finish and function return false
 */
void PeriodicTask::execWhile() {

    bool terminated = _task();

    if (!terminated && _timer.expires_from_now().total_milliseconds() > _interval) {

        throw std::runtime_error(TIMEOUTERROR + _info);

    } else if (terminated) {

        return ;

    } else {

        _timer.async_wait(std::bind(&PeriodicTask::execWhile, this));

    }

}

/**
 * @brief Stop exec (specialy if nCall == INFINITY
 */
void PeriodicTask::stop() {

    _nCall = 0;

}

/* *************************************************************************************************************
 * Periodic Scheduler class
 * ************************************************************************************************************/

/**
 * Start ioService
 */
void PeriodicScheduler::run() {

    _ioService.run();

}

/**
 * Clear ioService
 */
void PeriodicScheduler::clear() {

    _ioService.reset();

    _tasks.clear();
}

/**
 * Stop ioService (for example if call is infinity)
 */
void PeriodicScheduler::stop() {

    _ioService.stop();

}


/**
 * @brief Create new task into ioService for nCall
 *
 * @param task function we need to call and/or recall
 * @param interval_ms time between two call
 * @param nCall number of call
 */
void PeriodicScheduler::addTask(const handler &task, long interval_ms, int32_t nCall) {

    _tasks.push_back(std::make_unique<PeriodicTask>(_ioService, task, interval_ms, nCall));

}

/**
 * @brief Create new task into ioService that recall task if return false and timeout is not finish
 *
 * @param task function we need to call and/or recall if operation not terminated
 * @param timeout_ms timeout when we would like to recall task
 */
void PeriodicScheduler::addTaskWhile(const handler &task, long timeout_ms, const std::string &info) {

    _tasks.push_back(std::make_unique<PeriodicTask>(_ioService, task, timeout_ms, info));

}
