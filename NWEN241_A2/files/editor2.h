 #ifndef __EDITOR2_H__
 #define __EDITOR2_H__

 // #define

 int editor_count_lines(const char *editing_buffer, int bufflen);

 int editor_search_multiple(const char *editing_buffer, int bufflen, char *target, int *indexs, int size);



#endif /*__EDITOR2_H__*/
