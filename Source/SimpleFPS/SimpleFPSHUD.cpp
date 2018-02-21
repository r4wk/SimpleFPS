// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SimpleFPSHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"

ASimpleFPSHUD::ASimpleFPSHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;
	// Set the 2D gun texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> GunTexObj(TEXT("/Game/FirstPerson/FPWeapon/Textures/gun_pistol"));
	GunTex = GunTexObj.Object;
}


void ASimpleFPSHUD::DrawHUD()
{
	Super::DrawHUD();

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition((Center.X), (Center.Y + 20.0f));

	// magic numbers to replaced with img size
	const FVector2D GunDrawPosition((Center.X - 64.0f), (Center.Y + 160.0f));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );

	// draw 2D gun
	FCanvasTileItem GunTileItem(GunDrawPosition, GunTex->Resource, FLinearColor::White);
	const FVector2D GunDrawSize(128.0f, 128.0f);
	GunTileItem.Size = GunDrawSize;
	GunTileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(GunTileItem);
}
