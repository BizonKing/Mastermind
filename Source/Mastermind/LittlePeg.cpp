// Fill out your copyright notice in the Description page of Project Settings.

#include "LittlePeg.h"


// Sets default values
ALittlePeg::ALittlePeg()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("LittlePegBase"));
	}

	LittlePegSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("LittlePegSprite"));
	LittlePegSprite->SetSpriteColor(FLinearColor(0.0f, 0.0f, 0.0f, 1.0f));
	LittlePegSprite->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void ALittlePeg::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALittlePeg::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALittlePeg::SetLittlePegColor(TEnumAsByte<ELittlePegColors> newColor)
{
	LittlePegColor = newColor;
	UpdateSpriteColor();
}

void ALittlePeg::UpdateSpriteColor()
{
	switch (LittlePegColor)
	{
	case LP_NONE:
		LittlePegSprite->SetSpriteColor(FLinearColor(0.0f, 0.0f, 0.0f));
		break;
	case LP_WHITE:
		LittlePegSprite->SetSpriteColor(FLinearColor(255.0f, 255.0f, 255.0f));
		break;
	case LP_RED:
		LittlePegSprite->SetSpriteColor(FLinearColor(255.0f, 0.0f, 0.0f));
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("ALittlePeg::UpdateSpriteColor() Unexpected Error"))
		break;
	}
}
