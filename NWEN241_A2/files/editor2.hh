#include <iostream>
namespace editor2 {
    class EditorUtilities {
    public:
        static int countWords(const char *editing_buffer, int size_editting_buffer);
        static int searchMultipleNoCase(const char *editing_buffer, int length, std::string to_search, int *positions, int positions_length);
    };

}
