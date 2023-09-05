/*
 * An example of the TOML config thing
 */

#include "__generated.hpp"
#include <cstdio>
#include <cstdlib>

int main()
{
  const ChalkydriConfig *config = chalkydri_config();

  printf("fls: %x\nfrs: %x\nbls: %x\nbrs: %x\n", config->swerve.fl.steer.motorId, config->swerve.fr.steer.motorId, config->swerve.bl.steer.motorId, config->swerve.br.steer.motorId);

  return 0;
}

