// ---------------------------------------------------------
/**
 *  �z��������_���Ȑ��l�ŏ��������A
 *  ���e��S�č��v����������\������v���O����
 */
#include <stdio.h>
#include <random>
#include <time.h>

 // ---------------------------------------------------------
 /**
  * @brief          �z��̓��e�������_���Ȑ����ŏ���������
  * @param[in,out]  address     �z��̐擪�A�h���X�����|�C���^
  * @param[in]      size        �z��̃T�C�Y
  */
void initalizeArray(int *address , int size) {

    // �����_���Ȓl�𗘗p����ׂ̏���
    srand(time(NULL));

    // �����_���Ȓl�Ŕz��̓��e������������
    for (int i = 0; i < size; ++i) {
        // �z��̗v�f�̃A�h���X�� p �ɑ������
        int *p = address + i ;
        // 0 �` 9 �̃����_���Ȑ����������l�Ƃ��đ������
        *p = (rand() % 10);
    }
}


// ---------------------------------------------------------
/**
 * @brief          �z��̑��a���v�Z����
 * @param[in,out]  address     �z��̐擪�A�h���X�����|�C���^
 * @param[in]      size        �z��̃T�C�Y
 * @return         �z��̑��a
 */
int calcSum(int *address, int size) {

    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += *(address + i);
    }

    return sum;
}


// ---------------------------------------------------------
// main �֐��̒�`
// ---------------------------------------------------------
int main() {

    // �����^�̔z���錾����
    int a[10] = {};

    // �z�������������
    initalizeArray(a, sizeof(a) / sizeof(a[0]));

    // �z��̑��a���v�Z����
    int total = calcSum(a, sizeof(a) / sizeof(a[0]));

    printf("%d", total);

    return 0;
}