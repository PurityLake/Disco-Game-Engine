#include <memory>

namespace Disco {
namespace DataStructures {
    template <typename T>
    class Observer {
    protected:
        virtual void observe(T& obj) = 0;
    };
}
}