mkdir -p library
mkdir -p library/libpqxx
wget https://github.com/jtv/libpqxx/archive/6.1.1.tar.gz -P ./library
tar -xvf library/6.1.1.tar.gz -C ./library/libpqxx --transform 's!^[^/]\+\($\|/\)!libpqxx\1!'
cd ./library/libpqxx/
./autogen.sh
./configure
