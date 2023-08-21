#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "JNProjectile.generated.h"

// Declarations.
class USphereComponent;
class UProjectileMovementComponent;

UCLASS( Config = Game )
class JOYFRAMEWORK_API AJNProjectile : public AActor
{
	GENERATED_BODY( )

public:
	/** Sphere collision component */
	UPROPERTY( VisibleDefaultsOnly, Category = Projectile )
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Movement, Meta = ( AllowPrivateAccess = "true" ) )
	UProjectileMovementComponent* ProjectileMovement;

public:
	AJNProjectile( );

public:
	/** called when projectile hits something */
	UFUNCTION( )
	void OnHit( UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit );

	USphereComponent* GetCollisionComp( ) const { return CollisionComp; }
	UProjectileMovementComponent* GetProjectileMovement( ) const { return ProjectileMovement; }
};

