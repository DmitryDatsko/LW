#include <iostream>
#include <string> 
#include <fstream>
#include <regex>

using namespace std;

class LW8 {
public:
    static void Task1() {
        double x;
        cout << "Please enter a value of x: ";
        cin >> x;
        if (x > 1 && x < 1.5) {
            cout << "Y equal: " << (pow(x, 1 / 4)) + exp(pow(x, 2));
        }
        else if (x > 0 && x <= 1) {
            cout << "Y equal: " << sqrt(log(fabs(x)));
        }
        else {
            cout << "Y equal: " << (5 + sqrt(fabs(x))) / (2 + 2 * x);
        }
    }
};

class LW9 {
public:
    static void Task1() {
        double a = 1.24, b = 0.67, x_n = 10.2, x_k = 12.4, h = 0.43, y = 0, x;
        cout << "Please enter a value of x: ";
        cin >> x;
        for (double j = x_n; j <= x_k; j += h)
        {
            y += (a + pow(x, 1 / 3)) / pow(sin(b * x), 2);
            cout << "Y equal: " << y << endl;
        }
    }
    static void Task2() {
        double a = 1.24, b = 0.67, x_n = 10.2, x_k = 12.4, h = 0.43, y = 0, x;
        cout << "Please enter a value of x: ";
        cin >> x;
        while (x_n <= x_k) {
            y += (a + pow(x, 1 / 3)) / pow(sin(b * x), 2);
            cout << "Y equal: " << y << endl;
            x_n += h;
        }
    }
    static void Task3() {
        double a = 1.24, b = 0.67, x_n = 10.2, x_k = 12.4, h = 0.43, y = 0, x;
        cout << "Please enter a value of x: ";
        cin >> x;
        do {
            y += (a + pow(x, 1 / 3)) / pow(sin(b * x), 2);
            cout << "Y equal: " << y << endl;
            x_n += h;
        } while (x_n <= x_k);
    }
};

class LW10 {
public:
    static void Task1(int A[2], int B[2], int C[2], int A1[2], int B1[2], int C1[2]) {
        double S1, S2;
        S1 = (((A[0] - C[0]) * (B[1] - C[1])) - ((B[0] - C[0]) * (A[1] - C[1]))) / 2.0;
        S2 = (((A1[0] - C1[0]) * (B1[1] - C1[1])) - ((B1[0] - C1[0]) * (A1[1] - C1[1]))) / 2.0;
        if (S1 > S2) {
            cout << "S1 biggest than S2 and equal: " << S1;
        }
        else if (S1 == S2) {
            cout << "S1 equal S2: " << S1;
        }
        else {
            cout << "S2 biggest than S1 and equal: " << S2;
        }
    }
};

class LW11 {
public:
    static void Task1() {
        double array[] = { -0.1, 100, -99.1, 2.22, 14.33, -10.07, 0.033, 4.15, -15.01, 11, -31.01, -70.1 };
        double* dud = find(begin(array), end(array), 2);
        if (dud != end(array)) {
            cerr << "Found at position " << distance(array, dud) << endl;
        }
        else {
            cerr << "Not found" << endl;
        }
    }
public:
    static void Task2() {
        double matrixA[5][5] = {
        { 1.2, 0.8, -1.3, -0.8, 8 },
        { 4.5, 2.3, -5.1, 0, 8.1 },
        { 2.3, 2.6, 10.5, 3.5, 10 },
        { 9.5, -3.8, -3.3, 3.7, -7.2 },
        { 1.7, 6.8, 1.7, 1.5, 1.8 } };
        double matrixB[2] = { 4 ,4 };
        double result = 1;
        for (int i = 1; i <= 4; i++)
        {
            if (matrixA[i][i - 1] > 0) {
                result *= matrixA[i][i - 1];
            }

        };
        cout << "Result = " << result;
        cout << "matrixB = (" << matrixB[0] * result << ", " << matrixB[1] * result << ")";
    }

};

class LW12 {
public:
    static void Task1() {
        string userInput;
        getline(cin, userInput);
        if (userInput.find(' ') != string::npos)
            cout << "Your string contain space\n";
        else
            cout << "Your string doesn`t contain space\n";
        getline(cin, userInput);
        regex regex(" ");

        vector<string> out(
            sregex_token_iterator(userInput.begin(), userInput.end(), regex, -1),
            sregex_token_iterator()
        );
        for (int i = 0; i < out.size(); i++) {
            if (tolower(out[i][0]) == tolower(out[i][out[i].length() - 1])) {
                cout << out[i] + "\n";
            }
        }
    }
};

class LW13 {
public:
    static void Task1() {
        string line, outputStr;
        int i{};
        ofstream mainFile("main.txt");
        ofstream taskFile("task.txt");

        mainFile << "Datsko Dmitry\n417-AKIT\nDude" << endl;
        mainFile.close();
        ifstream in("main.txt");

        if (in.is_open())
        {
            while (getline(in, line))
            {
                taskFile << i << " " + line + "\n";
                i++;
            }
        }
        in.close();
        taskFile.close();
        ifstream output("task.txt");

        if (output.is_open())
        {
            while (getline(output, outputStr))
            {
                cout << outputStr << endl;
            }
        }
        output.close();
    }
};
int main()
{
    //LW8::Task1();
    /*LW9::Task1();*/
    //LW10::LoopStatements();
    /*int A[2] = { 1, 3 };
    int B[2] = { 2, -5 };
    int C[2] = { -8, 4 };
    int A1[2] = { 3, 2 };
    int B1[2] = { 1, -5 };
    int C1[2] = { 3, 1 };
    LW10::Task1(A, B, C, A1, B1, C1);*/
    //LW11::Task2();
    //LW12::Task1();
    //LW13::Task1();
    LW9::Task1();
    LW9::Task2();
    LW9::Task3();
}



