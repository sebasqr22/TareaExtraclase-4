#include <cstring>
#include <iostream>

using namespace std;

//Class that calculates de MD5 of a string
class MD5
{
public:
    typedef unsigned int size_type;

    //Default constructor
    MD5();
    //Constructor per parameter
    MD5(const string& text);
    //Updaters
    void update(const unsigned char *buf, size_type length);
    void update(const char *buf, size_type length);
    //Finalizer
    MD5& finalize();
    //Hexadecimal
    string hexdigest() const;
    friend ostream& operator<<(ostream&, MD5 md5);

private:
    void init();
    typedef unsigned char uint1; //8 bits
    typedef unsigned int uint4; //32 bits
    enum {blocksize = 64};

    void transform(const uint1 block[blocksize]);
    static void decryption(uint4 output[], const uint1 input[], size_type len);
    static void encryption(uint1 output[], const uint4 input[], size_type len);

    //Create buffer, counter, state and message-digest (result)
    bool finalized;
    uint1 buffer[blocksize];
    uint4 count[2];
    uint4 state[4];
    uint1 digest[16];

    //Low level logic operations
    static inline uint4 rotate_left(uint4 x, int n);
    static inline uint4 F(uint4 x, uint4 y, uint4 z);
    static inline uint4 G(uint4 x, uint4 y, uint4 z);
    static inline uint4 H(uint4 x, uint4 y, uint4 z);
    static inline uint4 I(uint4 x, uint4 y, uint4 z);
    static inline void FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
};

string md5(const string str);