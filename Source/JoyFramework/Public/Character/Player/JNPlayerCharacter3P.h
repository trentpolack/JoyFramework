#pragma once

#include "CoreMinimal.h"

#include "InputAction.h"

#include "JNPlayerCharacterBase.h"

#include "JNPlayerCharacter3P.generated.h"

// Declarations.
class USceneComponent;
class UCameraComponent;

class UInputMappingContext;
class UInputAction;

class UJNSpringArmComponent;

/**
 *	AJNPlayerCharacter3P Class Definition.
 *		General-purpose template for a 3P character.
 */
UCLASS( Config = Game, Blueprintable )
class JOYFRAMEWORK_API AJNPlayerCharacter3P : public AJNPlayerCharacterBase
{
	GENERATED_BODY( )

public:
	AJNPlayerCharacter3P( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

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
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = ( AllowPrivateAccess = "true" ) )
	TObjectPtr< UJNSpringArmComponent > CameraBoom;
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = ( AllowPrivateAccess = "true" ) )
	TObjectPtr< UCameraComponent > Camera3P;

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
	FORCEINLINE UCameraComponent* GetCameraComponent3P( ) const { return Camera3P; }
};