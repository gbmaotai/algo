#ifdef __cplusplus 
extern "C" { 
#endif

struct Node;
struct Node{
    int data;
    struct Node* next;
};

void testLink();
#ifdef __cplusplus 
} 
#endif 