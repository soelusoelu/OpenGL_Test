#include "PlayerActor.h"
#include "../Component/PlayerMoveComponent.h"
#include "../Component/TransformComponent.h"
#include "../Component/MeshComponent.h"
#include "../Component/SkeletonComponent.h"
#include "../Component/AnimationComponent.h"
#include "../Component/Collider/BoxComponent.h"

PlayerActor::PlayerActor(IGameMediator* iGameMediator, const char* tag) :
    Actor(iGameMediator, tag),
    mPlayerMove(new PlayerMoveComponent(this)),
    mMesh(new MeshComponent(this, "./res/character.msh")),
    mSkelton(new SkeletonComponent(this, "./res/character.skl")),
    mAnimation(new AnimationComponent(this, "./res/character.anm")),
    mBox(new BoxComponent(this)) {
}

void PlayerActor::updateActor(float deltaTime) {
}

void PlayerActor::drawActor() const {
    mMesh->draw();
}
