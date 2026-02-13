#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

typedef struct s_data
{
    int     *in;
    char    *ch;
    
}
class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& right);
        ~Serializer();
    
    public:
        static uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);

}

#endif
