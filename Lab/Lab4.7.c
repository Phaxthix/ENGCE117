/*มีการสร้างสตรัคท์ studentNode ที่ประกอบด้วยชื่อ อายุ และคะแนน GPA ของนักเรียน โดยมีการประกาศตัวแปรและกำหนดค่าใน main() ตามตัวอย่างดังนี้

จงเขียนฟังก์ชัน GoNext() ที่ใช้ในการตรวจสอบว่า now ชี้ไปยังโหนดถัดไปหรือไม่ หากมีก็ให้เปลี่ยน now ไปยังโหนดถัดไปและแสดงข้อมูลในโหนดนั้น และถ้าหาก now ชี้ไปยังโหนดสุดท้ายแล้ว ให้แสดงข้อความ "End of List".

คำอธิบาย:

สร้างโครงสร้าง studentNode ที่เก็บข้อมูลชื่อ (name), อายุ (age), และ GPA (gpa).
ฟังก์ชัน GoNext() จะต้องเปลี่ยน now ให้ไปยังโหนดถัดไป ถ้ามีโหนดถัดไป ให้แสดงข้อมูลของโหนดนั้น ถ้าไม่มีก็แสดง "End of List".

#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    float gpa;
    struct studentNode *next;
};

void saveNode(struct studentNode *child, char n[], int a, float g);
void GoNext(struct studentNode **now);

int main() {
    struct studentNode *start, *now;
    start = new struct studentNode;
    saveNode(start, "Alice", 20, 3.5);

    start->next = new struct studentNode;
    saveNode(start->next, "Bob", 22, 3.8);

    start->next->next = new struct studentNode;
    saveNode(start->next->next, "Charlie", 21, 3.7);

    now = start;

    GoNext(&now);  // Move to next node and print
    GoNext(&now);  // Move to next node and print
    GoNext(&now);  // Move to next node and print

    return 0;
}

void saveNode(struct studentNode *child, char n[], int a, float g) {
    strcpy(child->name, n);
    child->age = a;
    child->gpa = g;
    child->next = NULL;
}
*/