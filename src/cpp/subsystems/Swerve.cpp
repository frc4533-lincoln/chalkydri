#include "Swerve.hpp"

/*
 * Swerve module
 */

ChalkydriSwerveModule::ChalkydriSwerveModule(
  int    driveId,
  int    steerId,
  bool   driveRev,
  bool   steerRev,
  int    absEncId,
  double absEncOffset,
  bool   absEncRev
)
{
}

double ChalkydriSwerveModule::getDrivePosition()
{
  // enc.getPos()
}

double ChalkydriSwerveModule::getSteerPosition()
{
  // enc.getPos()
}

double ChalkydriSwerveModule::getDriveVelocity()
{
  // enc.getVel()
}

double ChalkydriSwerveModule::getSteerVelocity()
{
  // enc.getVel()
}

double ChalkydriSwerveModule::getAbsEncRad()
{
  double angle = /* this->absEnc.getAbsPos() */;
  angle *= PI / 180.0;
  angle %= 2.0 * PI;
  angle -= /* absEncOffsetRad */;

  if (angle < 0.0)
    angle += 2.0 * PI

  return angle * (/* this.absEncRev */ ? -1.0 : 1.0);
}

void ChalkydriSwerveModule::resetEncoders()
{
  // set drive enc pos to 0.0
  // set steer enc pos to this.getAbsEncRad()
}



/*
 * Swerve drive
 */

ChalkydriSwerve::ChalkydriSwerve(const ChalkydriSwerveDriveConfig *cfg)
{
  this->fl = new ChalkydriSwerveModule(
    cfg->fl.drive.motorId,
    cfg->fl.steer.motorId,
    cfg->fl.drive.encRev,
    cfg->fl.steer.encRev,
    cfg->fl.steer.absEncId,
    cfg->fl.steer.absEncOffset,
    cfg->fl.steer.absEncRev
  );
  this->fr = new ChalkydriSwerveModule(
    cfg->fr.drive.motorId,
    cfg->fr.steer.motorId,
    cfg->fr.drive.encRev,
    cfg->fr.steer.encRev,
    cfg->fr.steer.absEncId,
    cfg->fr.steer.absEncOffset,
    cfg->fr.steer.absEncRev
  );
  this->bl = new ChalkydriSwerveModule(
    cfg->bl.drive.motorId,
    cfg->bl.steer.motorId,
    cfg->bl.drive.encRev,
    cfg->bl.steer.encRev,
    cfg->bl.steer.absEncId,
    cfg->bl.steer.absEncOffset,
    cfg->bl.steer.absEncRev
  );
  this->br = new ChalkydriSwerveModule(
    cfg->br.drive.motorId,
    cfg->br.steer.motorId,
    cfg->br.drive.encRev,
    cfg->br.steer.encRev,
    cfg->br.steer.absEncId,
    cfg->br.steer.absEncOffset,
    cfg->br.steer.absEncRev
  );

  this->swerveMods = new ChalkydriSwerveModule[] {
    this->fl,
    this->fr,
    this->bl,
    this->br,
  };
}

void ChalkydriSwerve::zeroGyro()
{
  // ...
}

void ChalkydriSwerve::zeroYaw()
{
  // ...
}

double ChalkydriSwerve::getPitch()
{
  // ...
}

getGyroRotation()

getModulePositions()

setModuleStates()

void ChalkydriSwerve::setDriveSpeed(/* drv speed */ speed)
{
  // ...
}

void ChalkydriSwerve::drive

getSwerveTranslation()

double ChalkydriSwerve::getSwerveRotation()
{
  // ...
}

