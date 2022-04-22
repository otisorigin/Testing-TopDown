#include "TopDownPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TestingAttributeSet.h"

ATopDownPlayerCharacter::ATopDownPlayerCharacter(const FObjectInitializer& ObjInit) 
{
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
	AttributeSet = CreateDefaultSubobject<UTestingAttributeSet>("AttributeSet");
}

void ATopDownPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

    if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);

		MaxSpeedChangedDelegate = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
				AttributeSet->GetMaxSpeedAttribute()
		).AddUObject(this, &ATopDownPlayerCharacter::MaxSpeedChanged);
    }
    if (AttributeSet)
    {
        AttributeSet->SetMaxSpeed(1000.0f);
		GetCharacterMovement()->MaxFlySpeed = AttributeSet->GetMaxSpeed();
    }
}

void ATopDownPlayerCharacter::MaxSpeedChanged(const FOnAttributeChangeData& Data)
{
	OnMaxSpeedChanged.Broadcast(Data.NewValue, Data.OldValue);
    GetCharacterMovement()->MaxFlySpeed = Data.NewValue;
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

UAbilitySystemComponent* ATopDownPlayerCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}