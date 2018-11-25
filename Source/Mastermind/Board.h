// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Paper2D/Classes/PaperSpriteComponent.h"
#include "BigPeg.h"
#include "LittlePeg.h"
#include "Board.generated.h"

UCLASS()
class MASTERMIND_API ABoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoard();

	// Checks a Row of Pegs and gives feedback on them
	UFUNCTION(BlueprintCallable)
	void CheckAndGiveFeedBack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	// Board Sprite
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Board", meta = (AllowPrivateAccess = "true"))
	UPaperSpriteComponent* SpriteComponent;

	// Secret code that player needs to find
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Board", meta = (AllowPrivateAccess = "true"))
	TArray<TEnumAsByte<EBigPegColors>> SecretCode;

	int currRow = 1;

	// Rows in the board (12 of them)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ABigPeg*> bigPegRow1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ABigPeg*> bigPegRow2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ABigPeg*> bigPegRow3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ABigPeg*> bigPegRow4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ABigPeg*> bigPegRow5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ABigPeg*> bigPegRow6;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ABigPeg*> bigPegRow7;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ABigPeg*> bigPegRow8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ABigPeg*> bigPegRow9;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ABigPeg*> bigPegRow10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ABigPeg*> bigPegRow11;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ABigPeg*> bigPegRow12;

	// Sets of little pegs in the board (12 of them)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ALittlePeg*> littlePegRow1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ALittlePeg*> littlePegRow2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ALittlePeg*> littlePegRow3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ALittlePeg*> littlePegRow4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ALittlePeg*> littlePegRow5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ALittlePeg*> littlePegRow6;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ALittlePeg*> littlePegRow7;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ALittlePeg*> littlePegRow8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ALittlePeg*> littlePegRow9;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ALittlePeg*> littlePegRow10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ALittlePeg*> littlePegRow11;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mastermind Board", meta = (AllowPrivateAccess = "true"))
	TArray<ALittlePeg*> littlePegRow12;
	
};
