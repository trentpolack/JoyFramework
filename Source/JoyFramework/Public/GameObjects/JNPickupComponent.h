#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"

#include "Character/JNCharacter.h"

#include "JNPickupComponent.generated.h"

// Declaration of the delegate that will be called when someone picks this up
// The character picking this up is the parameter sent with the notification
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FOnPickup, AJNCharacter*, PickupCharacter );

UCLASS( Blueprintable, BlueprintType, ClassGroup = ( Custom ), meta = ( BlueprintSpawnableComponent ) )
class JOYFRAMEWORK_API UJNPickupComponent : public USphereComponent
{
	GENERATED_BODY( )

public:
	UJNPickupComponent( );

public:

	/** Delegate to whom anyone can subscribe to receive this event */
	UPROPERTY( BlueprintAssignable, Category = "Interaction" )
	FOnPickup OnPickup;

protected:
	/** Called when the game starts */
	virtual void BeginPlay( ) override;

	/** Code for when something overlaps this component */
	UFUNCTION( )
	void OnSphereBeginOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult );
};