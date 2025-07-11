#pragma once

class Observer {
public:
    virtual void onMarioCoinChanged(int newCoinCount) = 0;
    virtual ~Observer() = default;
};