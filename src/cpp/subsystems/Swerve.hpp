/*
 * Swerve drive
 *
 * Implementation based on <https://www.youtube.com/watch?v=0Xi9yb1IMyA>
 */

#include "../__generated.hpp"

struct ChalkydriSwerveModule
{
  public:
    ChalkydriSwerveModule(
      int    driveId,
      int    steerId,
      bool   driveRev,
      bool   steerRev,
      int    absEncId,
      double absEncOffset,
      bool   absEncRev
    );

    // Position traveled by the drive encoder in meters?
    double getDrivePosition();

    // Position traveled by the steer encoder in radians?
    double getSteerPosition();

    // Velocity of the drive encoder in meters per second
    double getDriveVelocity();

    // Velocity of the steer encoder in radians per second
    double getSteerVelocity();

    // Gives the position of the steer absolute encoder in radians, on a scale of 0 to 6.28
    double getAbsoluteEncoderRad();

    // Sets the drive encoder to position = 0 and the steer relative encoder to the position of the steer absolute encoder
    void resetEncoders();

  private:
};

enum ChalkydriDriveSpeed
{
  SLOW     = 0,
  STANDARD = 1,
  FAST     = 2,
};

class ChalkydriSwerve
{
  public:
    ChalkydriSwerve(const ChalkydriSwerveDriveConfig *cfg);

    void zeroGyro();

    void zeroYaw();

    double getPitch();

    /* Rot 2D */ getGyroRotation();

    /* swerve mod pos */ getModulePositions();

    void setModuleStates(/* swerve mod state */[] desiredStates);

    void setDriveSpeed(/* drive speed */ speed);

    void drive(/* translat 2D */ translation, double rotation, bool fieldRelative, bool isOpenLoop);

    /* translat 2D */ getSwerveTranslation();

    double getSwerveRotation();

    /* pose 2D */ getEstimatedPose();

    void resetSwervePose();

    void resetPoseEstimator(/* rotation 2D */ gyroAngle, /* swerve mod pos */[] modulePositions, /* pose 2D */ startPose);

    void stopDrive();

    void addVisionPose2d();

    void updatePoseEstimator();

    void driveDistance(double distanceMeters);

    void printModuleOffsets();

    void enableChargeStation(bool direction);

    void straightenWheels(double time);

    void driveOverChargeStation(bool direction);

    void adjustChargeStation();

    /* command */ followTrajectoryCommand(/* path planner trajectory */ path);

    /* @override */
    void periodic();

  private:
    // Front left swerve module
    ChalkydriSwerveModule *fl;
    // Front right swerve module
    ChalkydriSwerveModule *fr;
    // Back left swerve module
    ChalkydriSwerveModule *bl;
    // Back right swerve module
    ChalkydriSwerveModule *br;

    ChalkydriSwerveModule swerveMods[4];

    ChalkydriDriveSpeed driveSpeed;
};


