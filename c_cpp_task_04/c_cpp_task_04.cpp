#include <stdio.h>
#include <random>
#include <time.h>


//�e�p�����[�^�̓������\����
struct Parameter {
    char* name = NULL;
    int hp = 0;
    int speed = 0;
    int attack = 0;
    int defense = 0;
};

//�����Ŏ󂯎����Parameter�\���̂̃|�C���^�[����A���̒��g�������_���Ȓl�ŏ���������֐��B
/*���_
�@���̊֐��ł�Parameter�\���̂́uname�v�ϐ����A���̊֐����Ő錾���ꂽ�unames�v�񎟌��z��Ɋ܂܂�镶������g���ď��������Ă���B
�@���̂Ƃ��uname�v�ϐ��̏������́A���ۂ̕�����������Ă���킯�ł͂Ȃ��A�unames�v�񎟌��z��Ɋ܂܂�镶����̃A�h���X�������邱�Ƃŏ��������s���Ă���B
�@���������̕��@�ł́A�unames�v�񎟌��z��̃X�R�[�v��func�֐����ł��邽�߁Afunc�֐��𔲂���Ɓunames�v�񎟌��z��̕���������̃A�h���X�Ŏw�肷�邱�Ƃ��ł��Ȃ��Ȃ��Ă��܂��B
�@����΂��肩�A�������̃A�h���X�ɐV���ɕϐ������蓖�Ă��Ă����ꍇ�A���̕ϐ��ɑ΂��ĊԈ����������s���Ă��܂��A�\�����ʃG���[�Ɍq����\��������B
 
�@������
�@�@�uname�v�ϐ����|�C���^�[�^�ł͂Ȃ������񂪊i�[�ł���^�ɂ��A���ڕ�����ŏ���������B
�@�A�unames�v�񎟌��z����O���[�o���ϐ��Ő錾���Ă����B
�@�B�unames�v�񎟌��z���static�ȃ��[�J���ϐ��Ő錾����B*/

void func(Parameter* parameter) {
    char names[][32] = {
        "�v���C���[",
        "�G",
        "���̑�",
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

//�T�C�Y�� 5 ��Parameter�\���̂̔z���錾���A������func�֐����g���ă����_���Ȓl�ŏ���������B
int main() {
    srand(time(NULL));
    Parameter parameters[5] = {};
    int s = sizeof(parameters) / sizeof(Parameter);
    for (int i = 0; i < s; ++i) {
        func(&parameters[i]);
    }
    return 0;
}