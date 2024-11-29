// Copyright Epic Games, Inc. All Rights Reserved.

#include "homework2PickUpComponent.h"

Uhomework2PickUpComponent::Uhomework2PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void Uhomework2PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &Uhomework2PickUpComponent::OnSphereBeginOverlap);
}

void Uhomework2PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	Ahomework2Character* Character = Cast<Ahomework2Character>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
