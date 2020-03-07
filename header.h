#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct {
    int id;
    char name[30];
    char isDone[10];

} Todo;

void Menu();
void add();
void rm();
void addTodo(Todo *t);
int ucitajID(Todo* t);
void delLine(int id);
void toggleTodo(int id);

#endif // HEADER_H_INCLUDED
