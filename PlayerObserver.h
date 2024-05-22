#ifndef PLAYEROBSERVER_H
#define PLAYEROBSERVER_H

class PlayerObserver {
public:
    virtual void update() = 0;
    virtual ~PlayerObserver() = default;
};

#endif // PLAYEROBSERVER_H
