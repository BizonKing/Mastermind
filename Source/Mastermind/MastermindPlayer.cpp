// Fill out your copyright notice in the Description page of Project Settings.

#include "MastermindPlayer.h"


// Sets default values
AMastermindPlayer::AMastermindPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Checks to see if there is an existing RootComponent before creating one
	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("PlayerBase"));
	}

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	CameraComponent->bUsePawnControlRotation = false;
	CameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	CameraComponent->OrthoWidth = 540.0f;
	CameraComponent->AspectRatio = 540.0f / 960.0f;
	CameraComponent->AttachTo(RootComponent);
	CameraComponent->SetWorldRotation(FRotator(0.0f, 0.0f, 0.0f));

}

// Called when the game starts or when spawned
void AMastermindPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMastermindPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMastermindPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

