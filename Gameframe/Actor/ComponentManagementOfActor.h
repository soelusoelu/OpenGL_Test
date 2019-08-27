#pragma once

#include <list>
#include <unordered_set>
#include <memory>

class Component;

class ComponentManagementOfActor {
public:
    ~ComponentManagementOfActor();
    //各コンポーネントのstartを一度だけ実行
    void start();
    //所有するすべてのコンポーネントを更新
    void update(float deltaTime);
    //コンポーネントの追加
    void addComponent(Component* component);
    //全コンポーネントの取得
    const std::list<std::shared_ptr<Component>>& getAllComponents() const;

    //コンポーネントの取得
    template<typename T>
    std::shared_ptr<T> getComponent() const {
        std::shared_ptr<T> comp = nullptr;
        for (const auto& c : mStartComponents) {
            comp = std::dynamic_pointer_cast<T>(c);
            if (comp) {
                return comp;
            }
        }
        for (const auto& c : mComponents) {
            comp = std::dynamic_pointer_cast<T>(c);
            if (comp) {
                break;
            }
        }
        //最後まで見つからなければnullptrを返す
        return comp;
    }

private:
    std::unordered_set<std::shared_ptr<Component>> mStartComponents;
    std::list<std::shared_ptr<Component>> mComponents;
};

