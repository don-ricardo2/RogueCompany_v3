
#pragma once

#include <windows.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <iostream>
#include <dwmapi.h>
#include  <d3d9.h>
#include  <d3dx9.h>

#include "singleton.h"
#include "vector.h"
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "dwmapi.lib")


inline namespace RogueCompany
{
	class Variables : public Singleton<Variables>
	{
	public:
		const char* dwProcessName = "RogueCompany.exe";
		DWORD dwProcessId = NULL;
		uint64_t dwProcess_Base = NULL;
		HWND gameHWND = NULL;

		int actor_count = NULL;
		int ScreenHeight = NULL;
		int ScreenWidth = NULL;
		int ScreenLeft = NULL;
		int ScreenRight = NULL;
		int ScreenTop = NULL;
		int ScreenBottom = NULL;

		float ScreenCenterX = ScreenWidth / 2;
		float ScreenCenterY = ScreenHeight / 2;

		DWORD_PTR game_instance = NULL;
		DWORD_PTR u_world = NULL;
		DWORD_PTR local_player_pawn = NULL;
		DWORD_PTR local_player_array = NULL;
		DWORD_PTR local_player = NULL;
		DWORD_PTR local_player_root = NULL;
		DWORD_PTR local_player_controller = NULL;
		DWORD_PTR local_player_state = NULL;
		DWORD_PTR persistent_level = NULL;
		DWORD_PTR actors = NULL;



	};
#define GameVars RogueCompany::Variables::Get()

	class Offsets : public Singleton<Offsets>
	{
	public:

		DWORD offset_g_names = 0x6c7f180; // GNames
		DWORD offset_u_world = 0x6dee1b8; // GWorld
		DWORD offset_camera_manager = 0x2b8; // APlayerController -> PlayerCameraManager
		DWORD offset_camera_cache = 0x1aa0; //APlayerCameraManager -> CameraCachePrivate
		DWORD offset_persistent_level = 0x30; //UWorld -> PersistentLevel
		DWORD offset_game_instance = 0x188; //UWorld -> OwningGameInstance
		DWORD offset_local_players_array = 0x38; //UGameInstance -> LocalPlayers
		DWORD offset_player_controller = 0x30; //UPlayer -> PlayerController
		DWORD offset_apawn = 0x2a0; //APlayerController -> AcknowledgedPawn
		DWORD offset_root_component = 0x130; //AActor -> RootComponent
		DWORD offset_actor_array = 0x98; //UNetConnection -> OwningActor
		DWORD offset_actor_count = 0xa0; //UNetConnection -> MaxPacket
		DWORD offset_player_state = 0x240; //APawn -> PlayerState
		DWORD offset_actor_mesh = 0x280; //ACharacter -> Mesh
		DWORD offset_relative_location = 0x11c; //USceneComponent -> RelativeLocation
		DWORD offset_health = 0x538; //AKSCharacterFoundation -> Health
		DWORD offset_max_health = 0x286c; //AKSCharacter -> CachedMaxHealth
		DWORD offset_player_name = 0x300; // APlayerState -> PlayerNamePrivate
		DWORD BaseAccuracy = 0x6bc; // UKSWeaponAsset -> BaseAccuracy
		DWORD bDowned = 0x2899; // AKSCharacter -> bDowned
		DWORD offset_bKickbackEnabled = 0xbf8; // AKSPlayerController -> bKickbackEnabled
		DWORD bInRagdoll = 0x10c9; // AKSCharacter -> bInRagdoll
		DWORD bCanMoveWhileRevivingOther = 0x2a50; // AKSCharacter -> bCanMoveWhileRevivingOther
		DWORD ping = 0x228; // APlayerState -> Ping
		DWORD r_Team = 0x3a8; // AKSPlayerState -> r_Team
		DWORD r_TeamNum = 0x220; // AKSTeamState -> r_TeamNum
		DWORD EliminatedState = 0x458; // AKSPlayerState -> EliminatedState
		DWORD TimeDilation = 0x2e8; // AWorldSettings -> TimeDilation
		DWORD ActiveWeaponComponent = 0x2320; // AKSCharacter -> ActiveWeaponComponent[0xb]
		DWORD WeaponAsset = 0x148; // UKSWeaponComponent -> WeaponAsset
		DWORD bUnlimitedAmmo = 0x410; // UKSWeaponAsset -> bUnlimitedAmmo
		DWORD MaxLungeDistance = 0x9e4; //UKSWeaponAsset_Melee -> MaxLungeDistance
		DWORD MeleeSphereRadius = 0x9c4; //UKSWeaponAsset_Melee -> MeleeSphereRadius
		DWORD bRevealed = 0x12fc; //AKSCharacterBase -> bRevealed
		DWORD bIsSpawnImmune = 0x1518; //AKSCharacterBase -> bIsSpawnImmune
		DWORD bIgnoreCollisionWithTeammates = 0x4ed; //AKSCharacterFoundation -> bIgnoreCollisionWithTeammates /////////
		DWORD CurrentOverheal = 0xd90; //AKSCharacterBase -> CurrentOverheal
		DWORD offset_last_submit_time = 0x2ac; // AServerStatReplicator -> NumRelevantDeletedActors
		DWORD offset_last_render_time = 0x2b4; // AServerStatReplicator -> NumReplicatedActors
		DWORD offset_actor_id = 0x18; // actor id
		DWORD offset_bone_array = 0x478; // bone array
		DWORD offset_component_to_world = 0x1c0; // component to world
		DWORD CurrentQuickMeleeWeapon = 0x2218; //AKSCharacter -> CurrentQuickMeleeWeapon
		DWORD MeleeWeaponAsset = 0x898; //AKSWeapon_Melee -> MeleeWeaponAsset
		DWORD BaseEyeHeight = 0x22c; //APawn -> BaseEyeHeight
		DWORD AmmoInClip = 0x4bc; //AKSWeapon -> AmmoInClip
		DWORD ClipSize = 0x4c0; //AKSWeapon -> ClipSize
		DWORD DefaultFOV = 0x238; //APlayerCameraManager -> DefaultFOV
		DWORD NoSpread = 0x6bc; //UKSWeaponAsset -> BaseAccuracy
		DWORD firemodetype = 0x3a0; //UKSWeaponAsset -> FireModeType
		DWORD CurrentRevealColor = 0x1300; //AKSCharacterBase -> CurrentRevealColor
		DWORD CharacterMovement = 0x288; //ACharacter -> CharacterMovement
		DWORD KSCharacterOwner = 0x890; //UKSCharacterMovementComponent -> KSCharacterOwner
		DWORD SpawnImmuneOutlineColorEnemy = 0x1318; //AKSCharacterBase -> SpawnImmuneOutlineColorEnemy
		DWORD PreFireTime = 0x3b0; //UKSWeaponAsset -> PreFireTime
		DWORD RoundsPerBurst = 0x3a4; //UKSWeaponAsset -> RoundsPerBurst
		DWORD AimDownSightsFov = 0x5f8; //UKSWeaponAsset -> AimDownSightsFov
		DWORD PostReloadTime = 0x3f8; //UKSWeaponAsset -> PostReloadTime
		DWORD PreReloadTime = 0x3f4; //UKSWeaponAsset -> PreReloadTime
		DWORD trollnoreload = 0x3e8; //UKSWeaponAsset -> bCanEverReload
		DWORD trollnofire = 0x368; //UKSWeaponAsset -> bCanEverFire
		DWORD aimovershoulder = 0x5e4; //UKSWeaponAsset -> bCanEverAimOverShoulder
		DWORD aimdownsights = 0x5ec; //UKSWeaponAsset -> bCanEverAimDownSights
		DWORD ReloadType = 0x3f0; //UKSWeaponAsset -> ReloadType
		DWORD DamageCategory = 0x40; //UKSDamageTypeBase -> DamageCategory
		DWORD ReticleType = 0x421; //UKSWeaponAsset -> ReticleType
		DWORD WeaponEquipType = 0x290; //UKSWeaponAsset -> WeaponEquipType
		DWORD WalkSpeedModifier = 0x290; //UKSWeaponAsset -> WeaponEquipType
		DWORD ClipSize2 = 0x3ec; //UKSWeaponAsset -> ClipSize
		DWORD HeadDamageAmount = 0x56c; //UKSWeaponAsset -> HeadDamageAmount
		DWORD DamageAmount = 0x570; //UKSWeaponAsset -> DamageAmount
		DWORD LimbDamageAmount = 0x574; //UKSWeaponAsset -> LimbDamageAmount
		DWORD BurstShotIndex = 0x46c; //AKSWeapon -> BurstShotIndex
		DWORD PostFireTime = 0x3bc; //UKSWeaponAsset -> PostFireTime
		DWORD AltPostFireTime = 0x3c0; //UKSWeaponAsset -> AltPostFireTime
		DWORD PostFireForgivenessTime = 0x3c4; //UKSWeaponAsset -> PostFireForgivenessTime
		DWORD InitialPostFireTime = 0x3d4; //UKSWeaponAsset -> InitialPostFireTime
		DWORD FinalPostFireTime = 0x3d8; //UKSWeaponAsset -> FinalPostFireTime
		DWORD PostFireChargeTime = 0x3dc; //UKSWeaponAsset -> PostFireChargeTime
		DWORD PostFireDecayTime = 0x3e0; //UKSWeaponAsset -> PostFireDecayTime
		DWORD PostFireDecayDelay = 0x3e4; //UKSWeaponAsset -> PostFireDecayDelay
	};

#define GameOffset RogueCompany::Offsets::Get()
}
