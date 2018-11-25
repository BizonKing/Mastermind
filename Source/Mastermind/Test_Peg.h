// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Paper2D/Classes/PaperSpriteComponent.h"
#include "Test_Peg.generated.h"

UCLASS()
class MASTERMIND_API ATest_Peg : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATest_Peg();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Big Peg", meta = (AllowPrivateAccess = "true"))
	UPaperSpriteComponent* sprite;

	UFUNCTION(BlueprintCallable)
	void TestOnClickFunction();
	
};
