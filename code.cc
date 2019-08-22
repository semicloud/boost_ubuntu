#include <boost/log/trivial.hpp>
#include <boost/filesystem.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <iostream>

boost::mutex m;

void say_bye();

void say_bye()
{
    boost::lock_guard<boost::mutex> guard(m);
    std::cout << "Bye. (in thread " << boost::this_thread::get_id() << ")" << std::endl;
}

int main(int argc, char **argv)
{
    boost::filesystem::path p("\\usr\\local");
    if (boost::filesystem::is_directory(p))
    {
        BOOST_LOG_TRIVIAL(debug) << p << " is a directory";
    }
    else
    {
        BOOST_LOG_TRIVIAL(debug) << p << " is not a directory";
    }
    BOOST_LOG_TRIVIAL(info) << "Bye.";
    boost::thread t(say_bye);
    t.join();

    return 0;
}