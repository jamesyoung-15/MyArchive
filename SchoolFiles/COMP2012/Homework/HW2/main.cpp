#include <iostream>
#include <string>
#include "module.h"
#include "filter.h"
#include "handler.h"
#include "filterhandler.h"
#include "legoGPT.h"

using namespace std;

void test1()
{
    cout << "Welcome to PA2, basic tests for Module" << endl;
    FilterModule f1("basic filter", reserved);
    f1.print();
    HandlerModule h1("basic handler", "naiveHandler");
    h1.print();
    FilterHandlerModule fh1("basic filterHandler", reserved, "naiveFilterHandler");
    fh1.print();

    cout << "-------------------------end of test 1-------------------------" << endl;
    return;
}

void test2()
{
    cout << "-------------------------begin of test 2-------------------------" << endl;
    LegoGPT legoGPT;
    FilterModule f1("basic filter", reserved);
    HandlerModule h1("basic handler", "naiveHandler");
    FilterHandlerModule fh1("basic filterHandler", reserved, "naiveFilterHandler");
    legoGPT.LoadHandlerModule(h1);
    legoGPT.LoadFilterModule(f1);
    legoGPT.printHandlers();
    legoGPT.printFilters();
    legoGPT.LoadHandlerModule(fh1);
    legoGPT.LoadFilterModule(fh1);
    legoGPT.printHandlers();
    legoGPT.printFilters();
    cout << "Let's train simple handlers!" << endl;
    string question = "How are you?";
    h1.trainData(question, "Fine, thank you, and you?");
    cout << "Question is: " << question
         << " answer: " << h1.answer(question) << endl;

    legoGPT.clear();
    cout << "-------------------------end of test 2-------------------------" << endl;
    return;
}

void test3()
{
    cout << "-------------------------begin of test 3-------------------------" << endl;
    LegoGPT legoGPT;

    cout << "Basic tests for LegoGPT" << endl;
    HandlerModule mathHandler("Math handler", "math");
    mathHandler.trainData("What is 3 + 5", "3 + 5 = 8");
    string question = "What is 3 + 5";
    cout << "Question is " << question << endl;
    cout << mathHandler.answer("What is 3 + 5") << endl;
    legoGPT.clear();
    legoGPT.clear();
    cout << "-------------------------end of test 3-------------------------" << endl;
    return;
}

void test4()
{
    cout << "-------------------------begin of test 4-------------------------" << endl;
    LegoGPT legoGPT;

    HandlerModule mathHandler("Math handler", "math");
    mathHandler.trainData("What is 3 + 5", "3 + 5 = 8");

    legoGPT.LoadHandlerModule(mathHandler);
    string question = "What is 3 + 5";
    cout << "Question is " << question << endl;
    legoGPT.chat("math", question);
    string topic = "physics";
    cout << "Topic is " << topic << endl;
    legoGPT.chat(topic, "Tell me a joke.");
    legoGPT.clear();
    cout << "-------------------------end of test 4-------------------------" << endl;
    return;
}

void test5()
{
    cout << "-------------------------begin of test 5-------------------------" << endl;
    LegoGPT legoGPT;

    HandlerModule mathHandler("Math handler", "math");
    mathHandler.trainData("What is 3 + 5", "3 + 5 = 8");

    FilterModule martian("Martian filter", language);
    FilterHandlerModule humor("humor FilterHandlerModule", tone, "humor");
    humor.trainPostData("3 + 5 = 8", "I don't know what is 3 + 5, but I know 3 + 5 = 5 + 3. Because Integers under Addition form an Abelian Group.");
    humor.trainData("Tell me a joke.", "- Two strings walk into a bar. The bartender says, \"So what'll it be?\" The first string says, \"I think I\'ll have a beer^CjfdLk jk3s d#f67howe%^U r89nvy~~owmc63^Dz x.xvcu\" \"Please excuse my friend,\" the second string says, \"He isn\'t null-terminated.\" ");

    legoGPT.LoadHandlerModule(mathHandler);
    legoGPT.LoadHandlerModule(humor);
    legoGPT.LoadFilterModule(martian);
    legoGPT.LoadFilterModule(humor);
    legoGPT.printTopics();
    legoGPT.printLanguages();
    legoGPT.chat("math", "What is 3 + 5");
    legoGPT.chat("humor", "Tell me a joke.");
    legoGPT.clear();
    cout << "-------------------------end of test 5-------------------------" << endl;
    return;
}

void test6()
{
    cout << "-------------------------begin of test 6-------------------------" << endl;
    LegoGPT legoGPT;

    HandlerModule mathHandler("Math handler", "math");
    mathHandler.trainData("What is 3 + 5", "3 + 5 = 8");

    FilterModule martian("Martian filter", language);
    FilterHandlerModule humor("humor FilterHandlerModule", tone, "humor");
    humor.trainPostData("3 + 5 = 8", "I don't know what is 3 + 5, but I know 3 + 5 = 5 + 3. Because Integers under Addition form an Abelian Group.");
    humor.trainData("Tell me a joke.", "- Two strings walk into a bar. The bartender says, \"So what'll it be?\" The first string says, \"I think I\'ll have a beer^CjfdLk jk3s d#f67howe%^U r89nvy~~owmc63^Dz x.xvcu\" \"Please excuse my friend,\" the second string says, \"He isn\'t null-terminated.\" ");

    legoGPT.LoadHandlerModule(mathHandler);
    legoGPT.LoadHandlerModule(humor);
    legoGPT.LoadFilterModule(martian);
    legoGPT.LoadFilterModule(humor);
    // legoGPT.printTopics();
    // legoGPT.printLanguages();
    // legoGPT.chat("math", "What is 3 + 5");
    // legoGPT.chat("humor", "Tell me a joke.");
    //-------------------------same output as test 5 are comment out-------------------------
    cout << "Let's get a humorous math answer." << endl;
    mathHandler.setToneFilter(&humor);
    legoGPT.chat("math", "What is 3 + 5");
    cout << "Let's ask a math question in Martian." << endl;
    cout << "Before training:" << endl;
    legoGPT.chat("math", "adfv32zd4ve");
    martian.trainPreData("adfv32zd4ve", "What is 3 + 5");
    mathHandler.setLanguageFilter(&martian);
    cout << "After training:" << endl;
    legoGPT.chat("math", "adfv32zd4ve");
    legoGPT.clear();
    cout << "-------------------------end of test 6-------------------------" << endl;
    return;
}

void test7()
{
    cout << "-------------------------begin of test 7-------------------------" << endl;
    LegoGPT legoGPT;

    HandlerModule mathHandler("Math handler", "math");
    mathHandler.trainData("What is 3 + 5", "3 + 5 = 8");

    FilterModule martian("Martian filter", language);
    FilterHandlerModule humor("humor FilterHandlerModule", tone, "humor");
    humor.trainPostData("3 + 5 = 8", "I don't know what is 3 + 5, but I know 3 + 5 = 5 + 3. Because Integers under Addition form an Abelian Group.");
    humor.trainData("Tell me a joke.", "- Two strings walk into a bar. The bartender says, \"So what'll it be?\" The first string says, \"I think I\'ll have a beer^CjfdLk jk3s d#f67howe%^U r89nvy~~owmc63^Dz x.xvcu\" \"Please excuse my friend,\" the second string says, \"He isn\'t null-terminated.\" ");

    legoGPT.LoadHandlerModule(mathHandler);
    legoGPT.LoadHandlerModule(humor);
    legoGPT.LoadFilterModule(martian);
    legoGPT.LoadFilterModule(humor);
    // legoGPT.printTopics();
    // legoGPT.printLanguages();
    // legoGPT.chat("math", "What is 3 + 5");
    // legoGPT.chat("humor", "Tell me a joke.");
    // legoGPT.chat("physics", "Tell me a joke.");
    // cout << "Let's get a humorous math answer." << endl;
    mathHandler.setToneFilter(&humor);
    // legoGPT.chat("math", "What is 3 + 5");

    // cout << "Let's ask a math question in Martian." << endl;
    // cout << "Before training:" << endl;
    // legoGPT.chat("math", "adfv32zd4ve");
    martian.trainPreData("adfv32zd4ve", "What is 3 + 5");
    mathHandler.setLanguageFilter(&martian);
    // cout << "After training:" << endl;
    // legoGPT.chat("math", "adfv32zd4ve");

    //-------------------------same output as test 6 are comment out-------------------------
    //-------------------------below is added part for test 7-------------------------

    cout << "Let's ask for a joke in Martian." << endl;
    string question = "nzsuivnxni";
    cout << "Question is " << question << endl;
    cout << "Before training:" << endl;

    legoGPT.chat("humor", question);
    cout << "After training:" << endl;
    martian.trainPreData(question, "Tell me a joke.");
    humor.setLanguageFilter(&martian);
    legoGPT.chat("humor", question);
    legoGPT.clear();
    cout << "-------------------------end of test 7-------------------------" << endl;
    return;
}

void test8()
{
    cout << "-------------------------begin of test 8-------------------------" << endl;
    LegoGPT legoGPT;

    HandlerModule mathHandler("Math handler", "math");
    mathHandler.trainData("What is 3 + 5", "3 + 5 = 8");

    FilterModule martian("Martian filter", language);
    FilterHandlerModule humor("humor FilterHandlerModule", tone, "humor");
    humor.trainPostData("3 + 5 = 8", "I don't know what is 3 + 5, but I know 3 + 5 = 5 + 3. Because Integers under Addition form an Abelian Group.");
    humor.trainData("Tell me a joke.", "- Two strings walk into a bar. The bartender says, \"So what'll it be?\" The first string says, \"I think I\'ll have a beer^CjfdLk jk3s d#f67howe%^U r89nvy~~owmc63^Dz x.xvcu\" \"Please excuse my friend,\" the second string says, \"He isn\'t null-terminated.\" ");

    legoGPT.LoadHandlerModule(mathHandler);
    legoGPT.LoadHandlerModule(humor);
    legoGPT.LoadFilterModule(martian);
    legoGPT.LoadFilterModule(humor);
    // legoGPT.printTopics();
    // legoGPT.printLanguages();
    // legoGPT.chat("math", "What is 3 + 5");
    // legoGPT.chat("humor", "Tell me a joke.");
    // legoGPT.chat("physics", "Tell me a joke.");
    // cout << "Let's get a humorous math answer." << endl;
    mathHandler.setToneFilter(&humor);
    // legoGPT.chat("math", "What is 3 + 5");

    // cout << "Let's ask a math question in Martian." << endl;
    // cout << "Before training:" << endl;
    // legoGPT.chat("math", "adfv32zd4ve");
    martian.trainPreData("adfv32zd4ve", "What is 3 + 5");
    mathHandler.setLanguageFilter(&martian);
    // cout << "After training:" << endl;
    // legoGPT.chat("math", "adfv32zd4ve");

    martian.trainPreData("nzsuivnxni", "Tell me a joke.");
    // cout << "Let's ask for a joke in Martian." << endl;
    // cout << "Before training:" << endl;
    // legoGPT.chat("humor", "nzsuivnxni");
    // cout << "After training:" << endl;
    humor.setLanguageFilter(&martian);
    // legoGPT.chat("humor", "nzsuivnxni");

    //-------------------------same output as test 7 are comment out-------------------------
    //-------------------------below is added part for test 8-------------------------

    cout << "Let's ask for a Martian joke." << endl;
    martian.trainPostData("- Two strings walk into a bar. The bartender says, \"So what'll it be?\" The first string says, \"I think I\'ll have a beer^CjfdLk jk3s d#f67howe%^U r89nvy~~owmc63^Dz x.xvcu\" \"Please excuse my friend,\" the second string says, \"He isn\'t null-terminated.\" ", "aaaddd12e1dverhefdf5y3vdbrtszfdddvdbbnbsdbdsbd");
    legoGPT.chat("humor", "nzsuivnxni");

    cout << "Let's ask for a math joke in Martian." << endl;
    martian.trainPostData("I don't know what is 3 + 5, but I know 3 + 5 = 5 + 3. Because Integers under Addition form an Abelian Group.", "vzxcv4w2bv6qvdf");
    legoGPT.chat("math", "adfv32zd4ve");

    legoGPT.clear();
    cout << "-------------------------end of test 8-------------------------" << endl;
    return;
}

int main()
{
    // You are suggested to comment out the tests you haven't implemented and test the cases one by one.
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    cout << "End of all tests!" << endl;
    return 0;
}