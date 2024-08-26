/** \file
Данный файл содержит в себе функцию CleanBufer()
*/


#ifndef CLEANBUFER
#define CLEANBUFER


/**
    \brief Функция CleanBufer() предназначена для очистки буфера.

    CleanBufer() читает значения оставшиеся в буфере
    после использования функции scanf(). 
    \return False, если
    были прочитаны значения, отличные от "\n" и EOF, иначе выводится
    True. 
*/


int CleanBufer ();

#endif
