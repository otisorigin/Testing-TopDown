// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownPlayerController.h"
#include "Runtime/AIModule/Classes/Blueprint/AIBlueprintHelperLibrary.h"

ATopDownPlayerController::ATopDownPlayerController() 
{
    bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ATopDownPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void ATopDownPlayerController::MoveToMouseCursor()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, true, Hit);

	if (Hit.bBlockingHit)
	{
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void ATopDownPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ATopDownPlayerController::OnSetDestinationPressed);
}

void ATopDownPlayerController::OnSetDestinationPressed()
{
	MoveToMouseCursor();
}