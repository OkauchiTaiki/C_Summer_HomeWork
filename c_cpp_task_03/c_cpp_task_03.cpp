// ---------------------------------------------------------
/**
 *  Parameter ���ꗥ�� n �{����v���O�����A
 */
#include <stdio.h>


 // ---------------------------------------------------------
 /**
  * @brief �p�����[�^�\����
  */
struct Parameter
{
    int hp = 100;  // HP
    int speed = 10;   // �f����
    int attack = 20;   // �U����
    int defense = 20;   // �h���
};


// ---------------------------------------------------------
/**
 * @brief          Parameter �����S�Ă̓��e�� n �{����
 * @param[in,out]  param   n �{�������� Parameter �^�ϐ��̃A�h���X
 * @param[in]      n       �{��
 */
void buff(Parameter *param, int n) {

    param->hp *= n;
    param->speed *= n;
    param->attack *= n;
    param->defense *= n;
}

// ---------------------------------------------------------
/**
 * @brief          Parameter �^�����e�p�����[�^��\������
 * @param[in]      param   �\���������� Parameter �^�ϐ��̃A�h���X
 */
void dispParameter(Parameter* param) {

    printf("HP     : %d\n", (*param).hp);
    printf("�f���� : %d\n", (*param).speed);
    printf("�U���� : %d\n", (*param).attack);
    printf("�h��� : %d\n", (*param).defense);
}


// ---------------------------------------------------------
// main �֐��̒�`
// ---------------------------------------------------------
int main() {

    // Parameter �^�̕ϐ���錾����
    Parameter parameter = {};

    // �����O�̃p�����[�^��\������
    dispParameter(&parameter);

    // �S�p�����[�^�� 3 �{�ɋ�������
    buff(&parameter , 3);

    printf("---------������---------\n");
    // ������̃p�����[�^��\������
    dispParameter(&parameter);

    return 0;
}