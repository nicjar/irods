import os, stat
        
        # test basic informational commands
        assertiCmd(s.adminsession,"iinit -l", "LIST", s.adminsession.getUserName() )
        assertiCmd(s.adminsession,"iinit -l", "LIST", s.adminsession.getZoneName() )
        assertiCmd(s.adminsession,"iinit -l", "LIST", s.adminsession.getDefResource() )
        res = s.adminsession.runCmd('ils', ['-V'])
        assert (res[0].count('NOTICE: irodsHost') == 1
                and res[0].count('NOTICE: irodsPort') == 1
                and res[0].count('NOTICE: irodsDefResource') == 1)
        
        # new file mode check
        assertiCmd(s.adminsession,"iget -fK --rlock "+irodshome+"/icmdtest/foo2 /tmp/" )
        assert oct(stat.S_IMODE(os.stat("/tmp/foo2").st_mode)) == '0640'
        os.unlink( "/tmp/foo2" )
        