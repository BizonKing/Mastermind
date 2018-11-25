// Fill out your copyright notice in the Description page of Project Settings.

#include "Test_Peg.h"


// Sets default values
ATest_Peg::ATest_Peg()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TestPegBase"));
	}

	sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("TestPefSprite"));
	sprite->SetSpriteColor(FLinearColor(0.0f, 0.0f, 0.0f, 1.0f));
	sprite->AttachTo(RootComponent);

	// Binds the BigPegOnClickFunction delegate to OnClicked
	FScriptDelegate OnClickDelegate;
	OnClickDelegate.BindUFunction(this, FName("TestOnClickFunction"));
	OnClicked.AddUnique(OnClickDelegate);

}

// Called when the game starts or when spawned
void ATest_Peg::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATest_Peg::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATest_Peg::TestOnClickFunction()
{
	UE_LOG(LogTemp, Warning, TEXT("Test Peg Working?"))
}

