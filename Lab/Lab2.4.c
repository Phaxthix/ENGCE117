/*เขียนฟังก์ชัน explode() ที่สามารถแยกข้อความใน str1 เป็นหลายๆ ส่วนโดยใช้ตัวอักขระหรือหลายตัวอักขระใน splitters[] เป็นตัวแบ่งแยก ซึ่งจะต้องจัดการกรณีที่มีช่องว่าง หรือค่าที่ไม่ใช่ตัวอักขระในข้อความ โดยเก็บผลลัพธ์ใน str2[] และจำนวนข้อความที่แยกได้ใน count ซึ่งผลลัพธ์จะต้องไม่มีช่องว่างหรือค่าที่ไม่ได้ใช้ในแต่ละคำที่แยกออกมา

ข้อกำหนด

str1: ข้อความที่ต้องการแยก
splitters: ตัวอักขระที่ใช้เป็นตัวแบ่ง (สามารถมีหลายตัวได้)
str2: อาร์เรย์ที่ใช้เก็บผลลัพธ์ที่ได้จากการแยก
count: ตัวแปรที่ใช้เก็บจำนวนข้อความที่แยกได้

void explode(char str1[], char splitters[], char str2[][10], int *count);

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void explode(char str1[], char splitters[], char str2[][10], int *count) {
    int i = 0, j = 0, k = 0;
    *count = 0;

    while (str1[i] != '\0') {
        int isSplitter = 0;

        // ตรวจสอบว่าตัวอักษรปัจจุบันเป็นตัวแบ่งหรือไม่
        for (int s = 0; splitters[s] != '\0'; s++) {
            if (str1[i] == splitters[s]) {
                isSplitter = 1;
                break;
            }
        }

        if (isSplitter || isspace(str1[i])) { // ถ้าเป็นตัวแบ่งหรือช่องว่าง
            if (k > 0) { // ถ้ามีคำที่กำลังสร้างอยู่
                str2[j][k] = '\0'; // สิ้นสุดคำ
                j++; // ย้ายไปคำถัดไป
                k = 0; // รีเซ็ตตัวชี้อักขระ
            }
        } else {
            str2[j][k++] = str1[i]; // เพิ่มตัวอักษรลงในคำ
        }

        i++;
    }

    if (k > 0) { // เพิ่มคำสุดท้ายถ้ายังมีคำอยู่
        str2[j][k] = '\0';
        j++;
    }

    *count = j; // เก็บจำนวนคำที่แยกได้
}

int main() {
    char out[20][10]; // อาร์เรย์เก็บผลลัพธ์คำที่แยกได้
    int num;

    explode("I Love,You", ", ", out, &num); // เรียกใช้ฟังก์ชัน explode พร้อมตัวแบ่งหลายตัว

    printf("Split words:\n");
    for (int i = 0; i < num; i++) {
        printf("str2[%d] = %s\n", i, out[i]);
    }
    printf("Count = %d\n", num);

    return 0;
}
