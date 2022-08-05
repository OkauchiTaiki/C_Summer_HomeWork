#include <stdio.h>
#include <random>
#include <time.h>


//各パラメータの入った構造体
struct Parameter {
    char* name = NULL;
    int hp = 0;
    int speed = 0;
    int attack = 0;
    int defense = 0;
};

//引数で受け取ったParameter構造体のポインターから、その中身をランダムな値で初期化する関数。
/*問題点
　この関数ではParameter構造体の「name」変数を、この関数内で宣言された「names」二次元配列に含まれる文字列を使って初期化している。
　このとき「name」変数の初期化は、実際の文字列を代入しているわけではなく、「names」二次元配列に含まれる文字列のアドレスを代入することで初期化を行っている。
　しかしこの方法では、「names」二次元配列のスコープがfunc関数内であるため、func関数を抜けると「names」二次元配列の文字列を元のアドレスで指定することができなくなってしまう。
　そればかりか、もしそのアドレスに新たに変数が割り当てられていた場合、その変数に対して間違った操作を行ってしまい、予期せぬエラーに繋がる可能性がある。
 
　解決案
　①「name」変数をポインター型ではなく文字列が格納できる型にし、直接文字列で初期化する。
　②「names」二次元配列をグローバル変数で宣言しておく。
　③「names」二次元配列をstaticなローカル変数で宣言する。*/

void func(Parameter* parameter) {
    char names[][32] = {
        "プレイヤー",
        "敵",
        "その他",
    };
    int nameIndex = rand() % 3;
    int hp = rand() % 100;
    int speed = rand() % 10;
    int attack = rand() % 20;
    int defense = rand() % 20;
    parameter->name = names[nameIndex];
    parameter->hp = hp;
    parameter->speed = speed;
    parameter->attack = attack;
    parameter->defense = defense;
};

//サイズが 5 のParameter構造体の配列を宣言し、それらをfunc関数を使ってランダムな値で初期化する。
int main() {
    srand(time(NULL));
    Parameter parameters[5] = {};
    int s = sizeof(parameters) / sizeof(Parameter);
    for (int i = 0; i < s; ++i) {
        func(&parameters[i]);
    }
    return 0;
}