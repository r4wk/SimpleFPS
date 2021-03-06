// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SimpleFPSHUD.generated.h"

UCLASS()
class ASimpleFPSHUD : public AHUD
{
	GENERATED_BODY()

public:
	ASimpleFPSHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;
private:
	/** First person 2D gun asset pointer */
	class UTexture2D* GunTex;

};

