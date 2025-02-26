using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(ΕxamsFile.Startup))]
namespace ΕxamsFile
{
    public partial class Startup {
        public void Configuration(IAppBuilder app) {
            ConfigureAuth(app);
        }
    }
}
