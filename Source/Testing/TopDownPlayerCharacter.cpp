#include "TopDownPlayerCharacter.h"

ATopDownPlayerCharacter::ATopDownPlayerCharacter(const FObjectInitializer& ObjInit) 
{

}

void ATopDownPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ATopDownPlayerCharacter::OnMoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ATopDownPlayerCharacter::OnMoveRight);
}

void ATopDownPlayerCharacter::OnMoveForward(float Amount) 
{
    if(Amount == 0.0f) return;
    AddMovementInput(GetActorForwardVector(), Amount);  
}

void ATopDownPlayerCharacter::OnMoveRight(float Amount) 
{
    if(Amount == 0.0f) return;
    AddMovementInput(GetActorRightVector(), Amount);
}