#include <iostream>
#include <thread>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
//    thread().detach();
    int i = 0;
    if (i == 0) {
        throw invalid_argument("Hi");
    }
    return "01:02:03";
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer();
        }
        catch(system_error) {
            return last_fetched_time;
        }
        catch (exception) {
            throw;
        }
        return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}