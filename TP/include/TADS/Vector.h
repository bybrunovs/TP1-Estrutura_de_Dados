

namespace TADS
{
    template <typename T>

    class Vector
    {
    private:
        T *_dados;
        unsigned _tamanho;
        unsigned _capacidade;

    public:
        Vector(unsigned capacidade);
        Vector(const Vector &outro);
        void push_back(const T &elemento);
        ~Vector();
    };

} // namespace TADS