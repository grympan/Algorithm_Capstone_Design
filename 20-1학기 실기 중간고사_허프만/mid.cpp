#include <iostream> 
#include <cstring>
using namespace std;

#define MAX_TREE_HT 100 

struct nodeType {
    char symbol;
    int frequency;
    struct nodeType* left;
    struct nodeType* right;
};

struct MinHeap {
    int size;
    int capacity;
    struct nodeType** array;
};

struct nodeType* newNode(char key, int freq) {
    struct nodeType* temp = new nodeType;

    temp->left = temp->right = NULL;
    temp->symbol = key;
    temp->frequency = freq;

    return temp;
}

void minHeapify(struct MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size
        && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size
        && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != index) {
        swap(minHeap->array[smallest], minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

void insert(struct MinHeap* minHeap, struct nodeType* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

struct nodeType* remove(struct MinHeap* minHeap) {
    struct nodeType* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = new MinHeap;

    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = new nodeType * [capacity * sizeof(struct nodeType)];

    return minHeap;
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; i++)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

struct nodeType* buildHuffmanTree(char data[], int freq[], int size) {
    struct nodeType* left, * right, * r;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (minHeap->size != 1) {
        left = remove(minHeap);
        right = remove(minHeap);

        r = newNode('r', left->frequency + right->frequency);

        r->left = left;
        r->right = right;

        insert(minHeap, r);
    }

    return remove(minHeap);
}

int w = 0;
int sizebox[255];
char letterbox[255];

void printCodes(struct nodeType* root, int arr[], int r) {
    if (root->left) {
        arr[r] = 0;
        printCodes(root->left, arr, r + 1);
    }

    if (root->right) {
        arr[r] = 1;
        printCodes(root->right, arr, r + 1);
    }
    
    if (!(root->left) && !(root->right)) {
        letterbox[w] = root->symbol;
        sizebox[w] = r;
        w++;
    }
}

void HuffmanCodes(char key[], int freq[], int size) {
    struct nodeType* root
        = buildHuffmanTree(key, freq, size);

    int arr[MAX_TREE_HT], top = 0;

    printCodes(root, arr, top);
}

#define ASIZE 26
int main()
{
    char arr[ASIZE] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
    int freq[ASIZE] = { 0, };
    char text[100];

    cin.getline(text, 100);

    for (int i = 0; i < strlen(text); i++)
        for (int j = 0; j < ASIZE; j++)
            if (text[i] == arr[j])
                freq[j]++;


    int k, right = ASIZE - 1;
    while (right > 0) {
        k = 0;
        for (int i = 0; i < right; i++)
            if (freq[i + 1] > freq[i]) {
                swap(freq[i], freq[i + 1]);
                swap(arr[i], arr[i + 1]);
                k = i;
            }
        right = k;
    }

    int size = 0;
    for (int i = 0; i < ASIZE; i++)
        if (freq[i] != 0)
            size++;

    HuffmanCodes(arr, freq, size);

    int t = 0;
    for (int i = 0; i < strlen(text); i++)
        for (int j = 0; j < w; j++)
            if (text[i] == letterbox[j])
                t = t + sizebox[j];

    cout << t;
    return 0;
}