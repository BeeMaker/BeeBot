//
// Created by barbarin on 23/02/18.
//

#pragma once

#include <boost/noncopyable.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/placeholders.hpp>
#include <boost/system/error_code.hpp>

#define INFINY -1
#define TIMEOUTERROR "Error: Timeout: "

/**
 * @class PeriodicTask
 * @brief Manage all call injected by scheduler class (cf PeriodicScheduler)
 *
 */
class PeriodicTask {
public:

    using handler = std::function<bool ()>;

    /**
     * @enum stateTask
     * @brief manage state of task
     */
    enum stateTask {
        NONSTOP = -1,   ///< Infinity mode. Recall while task stop isn't calling
        DONE = 0,       ///< Task is done, Consume all nCall of task stop is called
        CURRENT = 1     ///< Number Task need to will be consum
    };

    /**
     * @brief Constructor for exec system with life. For example if we would like to do N photo with camera all
     * 1300 ms. Can execute multiple task in order by Scheduler
     *
     * @param ioService task order from PeriodicScheduler
     * @param task function we want to call
     * @param interval_ms time after recall task while nCall
     * @param nCall number of call
     *
     */
    PeriodicTask(boost::asio::io_service &ioService,
                 handler task,
                 long interval,
                 int32_t nCall);

    /**
     * @brief Constructor for exec system with timeout. Recall task if not true while timeout is not done. Can execute multiple
     * task in order by scheduler
     *
     * @param ioService task order from PeriodicScheduler
     * @param task function we want to call
     * @param interval_ms time after we stop to recall task
     * @param info data string for specify call location in case of Timeout error
     */
    PeriodicTask(boost::asio::io_service &ioService,
                 handler task,
                 long interval_ms,
                 const std::string &info);

    ~PeriodicTask();

    /**
     * No construction copyable
     * @param other
     */
    PeriodicTask( const PeriodicTask& other ) = delete; // non construction-copyable
    /**
     * No copyable operator
     * @param PeriodicTask
     */
    PeriodicTask& operator=( const PeriodicTask& ) = delete; // non copyable

    void exec();
    void execWhile();
    void stop();


private:

    boost::asio::io_service     &_ioService;
    boost::asio::deadline_timer _timer;
    handler                     _task;
    long                        _interval;
    int32_t                     _nCall;
    std::string                 _info = "";
};

class PeriodicScheduler {

public:

    using handler = std::function<bool ()>;
    /**
     *
     * @param other
     */

    void run();
    void stop();
    void clear();
    void addTask(const handler &task, long interval_ms = 200, int32_t nCall = 1);
    void addTaskWhile(const handler &task, long interval_ms = 200, const std::string &info = "");

private:
    boost::asio::io_service                     _ioService;
    std::vector<std::unique_ptr<PeriodicTask>>  _tasks;


};

