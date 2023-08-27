#pragma once

#include "CoreMinimal.h"

#include "InputAction.h"

#include "JNPlayerCharacterBase.h"

#include "JNPlayerCharacter1P.generated.h"

// Declarations.
class USkeletalMeshComponent;
class UCameraComponent;

/**
 *	AJNPlayerCharacter1P Class Definition.
 *		General-purpose template for a 1P character.
 */
UCLASS( Config = Game, Blueprintable )
class JOYFRAMEWORK_API AJNPlayerCharacter1P : public AJNPlayerCharacterBase
{
	GENERATED_BODY( )

public:
	AJNPlayerCharacter1P( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

protected:
	/**
	 *	Core Input Properties.
	 */
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Input, meta = ( AllowPrivateAccess = "true" ) )
	UInputMappingContext* InputMappingContext;

	// Basic look/movement functionality.
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Input, meta = ( AllowPrivateAccess = "true" ) )
	UInputAction* MoveAction;
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Input, meta = ( AllowPrivateAccess = "true" ) )
	UInputAction* LookAction;

	/**
	 *	Visual Properties. 
	 */
	
	// 1P Skeletal Mesh.
	UPROPERTY( VisibleDefaultsOnly, Category = Mesh )
	TObjectPtr< USkeletalMeshComponent > SKMFirstPerson = nullptr;

	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = ( AllowPrivateAccess = "true" ) )
	TObjectPtr< UCameraComponent > Camera1P = nullptr;

protected:
	/**
	 *	AActor Overrides.
	 */
	virtual void BeginPlay( ) override;
	virtual void EndPlay( const EEndPlayReason::Type EndPlayReason ) override;

	/**
	 *	APawn Overrides.
	*/
	virtual void SetupPlayerInputComponent( UInputComponent* PlayerInputComponent ) override;


public:
	/**
	 *	AJNCharacter Overrides.
	 */
	virtual void Reset( ) override;

	/**
	 *	Input Response.
	 */
	UFUNCTION( Category = "Player|Input", BlueprintNativeEvent )
	void OnMoveAction( const FInputActionValue& Value );
	UFUNCTION( Category = "Player|Input", BlueprintNativeEvent )
	void OnLookAction( const FInputActionValue& Value );

	/**
	 *	Accessors.
	 */
	FORCEINLINE USkeletalMeshComponent* GetSkeletalMesh1P( ) const { return SKMFirstPerson; }
	FORCEINLINE UCameraComponent* GetCameraComponent1P( ) const { return Camera1P; }
};