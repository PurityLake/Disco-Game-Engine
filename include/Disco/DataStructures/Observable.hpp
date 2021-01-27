#include <vector>

#include "Observer.hpp"

namespace Disco {
namespace DataStructures {
    template <typename T>
    class Observerable {
    private:
        std::vector<Observer<T>> toUpdate;
        
    public:
        void updateObservers() {
            for (auto obs : toUpdate) {
                obs.update(*this);
            }
        }
    };
}
}