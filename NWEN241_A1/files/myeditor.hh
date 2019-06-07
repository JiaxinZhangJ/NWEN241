/**
 * myeditor.hh
 *
 * You must define a class that extends the EditingBuffer class in this file.
 * Consult the assignment handout for more information.
 *
 * Student ID:300390526
 * Name:Yongbo Yu
 */
 #ifndef __MYEDITOR_HH__
 #define __MYEDITOR_HH__
 #include "editor.hh"
 #include <iostream>
 #include <cstring>
namespace editor{
    class MyEditingBuffer : public EditingBuffer {
    public:
       bool replace(char c, char replacement, int offset);
       int replace(std::string str, std::string replacement, int offset);
       void justify(char **viewingBuffer, int rows, int cols);
       // void setBuffer(const char *b, int len) {
       //     memcpy(buffer, b, len < BUFFER_LEN ? len : BUFFER_LEN);
       // }
       // MyEditingBuffer(){}//constructors
       // char buffer[BUFFER_LEN];
    };
}

#endif /* __MYEDITOR_HH__ */
