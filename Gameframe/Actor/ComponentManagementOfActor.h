#pragma once

#include <vector>
#include <unordered_set>

class Component;

class ComponentManagementOfActor {
public:
    ComponentManagementOfActor();
    ~ComponentManagementOfActor();
    //各コンポーネントのstartを一度だけ実行
    void start();
    //所有するすべてのコンポーネントを更新
    void update(float deltaTime);
    //コンポーネントの追加・削除
    void addComponent(Component* component);
    void removeComponent(Component* component);
    //全コンポーネントの取得
    const std::vector<Component*>& getAllComponents() const;

    //コンポーネントの取得
    template<typename T>
    T* getComponent() const {
        T* comp = nullptr;
        for (const auto& c : mStartComponents) {
            comp = dynamic_cast<T*>(c);
            if (comp) {
                return comp;
            }
        }
        for (const auto& c : mComponents) {
            comp = dynamic_cast<T*>(c);
            if (comp) {
                break;
            }
        }
        //最後まで見つからなければnullptrを返す
        return comp;
    }

private:
    std::unordered_set<Component*> mStartComponents;
    std::vector<Component*> mComponents;

};

