#pragma once


#include "GameFramework/Character.h"
#include "TopDownPlayerCharacter.generated.h"

UCLASS()
class ATopDownPlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ATopDownPlayerCharacter(const FObjectInitializer& ObjInit);

    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

private:

    void OnMoveForward(float Amount);
    void OnMoveRight(float Amount);
};