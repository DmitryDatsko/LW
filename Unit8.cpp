#include <iostream>
#include <string> 
#include <fstream>
#include <regex>

using namespace std;

class LW8 {
public:
    static int Task1() {
        double x;
        std::cout << "Please enter a value of x: ";
        std::cin >> x;
        if (x > 1 && x < 1.5) {
            std::cout << "First if";
            std::cout << "Y equal: " << (pow(x, 1 / 4)) + exp(pow(x, 2));
            return 0;
        }
        if (x > 0 && x <= 1) {
            std::cout << "Y equal: " << sqrt(log(fabs(x)));
            return 0;
        }
        else {
            std::cout << "Else";
            std::cout << "Y equal: " << (5 + sqrt(fabs(x))) / (2 + 2 * x);
            return 0;
        }
    }
};

class LW9 {
public:
    static int Task1() {
        double a = 1.24, b = 0.67, x_n = 10.2, x_k = 12.4, h = 0.43, y = 0, x;
        for (x = x_n; x <= x_k; x += h)
        {
            y = (a + pow(x, 1 / 3)) / pow(sin(b * x), 2);
        }
        std::cout << "Y equal: " << y;
        return 0;
    }
};

class LW10 {
public:
    static int Task1(int A[2], int B[2], int C[2], int A1[2], int B1[2], int C1[2]) {
        double S1, S2;
        S1 = (((A[0] - C[0]) * (B[1] - C[1])) - ((B[0] - C[0]) * (A[1] - C[1]))) / 2.0;
        S2 = (((A1[0] - C1[0]) * (B1[1] - C1[1])) - ((B1[0] - C1[0]) * (A1[1] - C1[1]))) / 2.0;
        if (S1 > S2) {
            std::cout << "S1 biggest than S2 and equal: " << S1;
            return 0;
        }
        if (S1 == S2) {
            std::cout << "S1 equal S2: " << S1;
            return 0;
        }
        else {
            std::cout << "S2 biggest than S1 and equal: " << S2;
            return 0;
        }
    }
};

class LW11 {
public:
    static void Task1() {
        double array[] = { -0.1, 100, -99.1, 2.22, 14.33, -10.07, 0.033, 4.15, -15.01, 11, -31.01, -70.1 };
        double* dud = std::find(std::begin(array), std::end(array), 2);
        if (dud != std::end(array)) {
            cerr << "Found at position " << std::distance(array, dud) << endl;
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
        std::cout << "Result = " << result;
        std::cout << "matrixB = (" << matrixB[0] * result << ", " << matrixB[1] * result << ")";
    }

};

class LW12 {
public:
    static void Task1(){
        string userInput;
        getline(cin, userInput);
        if (userInput.find(' ') != string::npos)
            cout << "Your string contain space\n";
        else
            cout << "Your string doesn`t contain space\n";
        getline(cin, userInput);
        std::regex regex(" ");

        std::vector<std::string> out(
            std::sregex_token_iterator(userInput.begin(), userInput.end(), regex, -1),
            std::sregex_token_iterator()
        );
        for (int i = 0; i < out.size(); i++) {
            if(tolower(out[i][0]) == tolower(out[i][out[i].length() - 1])) {
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
        std::ofstream mainFile("main.txt");
        std::ofstream taskFile("task.txt");

        mainFile << "Datsko Dmitry\n417-AKIT\nDude" << std::endl;
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
                std::cout << outputStr << std::endl;
            }
        }
        output.close();
    }
};
int main()
{
    //LW9::ConditionalStatements();
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
    LW13::Task1();
    
}



