object FEmpresasView: TFEmpresasView
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Ficha Cadastral de Empresas'
  ClientHeight = 579
  ClientWidth = 1100
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 18
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 18
  object PanelOptions: TPanel
    Left = 0
    Top = 531
    Width = 1100
    Height = 48
    Align = alBottom
    TabOrder = 0
    object Modificar: TSpeedButton
      Left = 34
      Top = 10
      Width = 121
      Height = 30
      Caption = 'MODIFICAR'
      Glyph.Data = {
        F6060000424DF606000000000000360000002800000018000000180000000100
        180000000000C0060000120B0000120B00000000000000000000C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0BBBFB971AD594BA22629900028930023A2012A8E
        0128900253A23586B276C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0B7
        C0B3C0C0C0C0C0C0C0C0C0C0C0C0C0C0C05FA8422F99002CBD0025D30018E200
        17DE0014DA0016DA021BDA0426CC0628B5062F99056CAF55C0C0C0C0C0C0C0C0
        C0C0C0C099BB8F28A706C0C0C0C0C0C0C0C0C0B0BDAA28920026AC001EDD001B
        E2001CE0001BDE001CDE001EDB031EDC0524DC0826DE0B27DF0C2CDD0E29B208
        31A20DB1BEADC0C0C057A7461EA20727B60AC0C0C0C0C0C0B0BDAA2B93001EC3
        0018DF001DE0001DDF001CDF0021E00222E00429E1082EE20C32E30F35E31235
        E11532E0152FE7172CCE0F20990524871419B50938F3322CC00CC0C0C0C0C0C0
        2C97001BBD0015DC001CDE001DDF001EDF0022E00328E3062AE3092EE50D33E4
        0F37E6143FE81945E91F43E8223EE72338E8222CD91622CB1132E62A45F33D28
        C20CC0C0C05FA84224A90014DA0018D9001ADD001FE00124E20428E5092DD107
        3BC9103FBA105ED43C70E26991F79F61EF4F4DED2B53EE354EED3646ED333FEB
        3449EE4056F55330CA12BBBFB9298F0015D10013D40015D5001CDC0222E1052F
        DF0939B20738A40F7AB264A7BC9E82B97069B74C31B30958D64A9DFCAF5FF242
        65F1505CF14F5BF15264F55E70FA7437D4166EA85922AF0010D50013D10019D5
        0224E00632E00A46BA098CBD73C0C0C0C0C0C0C0C0C0C0C0C0C0C0C074B5631C
        9D047AF0836DF45774F66472F66A73F86E7BF87C82FC8B40DB1C479A2817C300
        12D40118D60321DC062CE40C46C30B85BF66C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C04CA9382EB9146EF47C59F24170F56275F76A7CF97A82FA8588FA8D8EFE9A3F
        DF1D2D990223AB021BBC021FD40625E00A32DD0E4AB614C0C0C0C0C0C0C0C0C0
        C0C0C0B2C1AC2DB1091D9F086BE67BB9FFCDC0FECEA5FEB58FFC9D74F8777CFB
        8086FC8E8DFD9B3FE320C0C0C0B7BEB29ABA8B57AF3038B20938B80965B545C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C094BA8C63B3562CA01C23BA0F3ED53C
        7CF290CBFFDAB8FFCCABFFBF9CFFB138E21BA9510ABAA08DC0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C089BE8158BA4B22BB122CD21F59E865ACFEBF38DE28C47622E3B060
        E3B060CF8832CF8832BA804DBEA084C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C082C9792D
        DA18B55B00EBB32BF0CA63F8E19FFFF0CAF2D496E5B167D58F36C27325C49360
        C4AD93C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0D5A863E7AD42E8AA3EDEAC
        53C0C0C0C0C0C0C0C0C0BB5F03E29501E09506E39A0DE5A31CEFC55DF6D890FD
        EBBEFEEDC7F5DA9ED78F32D28324C2BAAFC0C0C0C0C0C0C0C0C0C0C0C0DF9E38
        FADD81FEE696FCE38EF9D573F4D075EFB841BC6106E29906E39A0FE49F19E7A4
        23E7A92AEAAB31ECB032F5D57FDFA54FCC8F4BC0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0D1AF7AE7AB3EFEE491FCE491FEE592FFEAB0FCE8BAE6B958BD6509E29C09
        E39C12E5A11BE7A727E9AD31EBAF36F2CF7CCC781AC79D6EC0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0CDB184E39F32FADA7DFCE18FFDE392FEE38FFFF2D1F6D47CD9
        BC7BC1660AE39C09E39E14E6A21EE7A829EAAE35EAB036F9DFA1E9BE77D28322
        CD9A5CCAA97DC5B7A5CEAB77DC9A36E4A338F7D779FDE18DFCE08EFDE28FFEE8
        AAFFF0D5EFB538C2C0BCC2690DE59C0CE49F18E7A523E9AB2CEAAF36EDB33EED
        B640F4CC6DF9E4A9F2CF8FECC376E5AA4DEEBE5EF1C964FCDE85FBDE87FCE08B
        FCE08CFEE59BFFF5DFF4CE6EDFBB6DC0C0C0C36B0FE59D0EE7A41BE19A1FE7A7
        35ECB339EDB540EEBA48F0BE4EF0C252F3C75DF5CC68F7D171F8D576FAD87DFA
        DA80FBDD85FCDF88FDE49BFFF2D3FBE3AAEFB63BC0C0C0C0C0C0C56F12E8A412
        D7881BC17329CB7824E5A943EFBA43EEBC4AF0C052F2C55AF4C963F5CD6AF6D2
        71F8D477F9D87DFADA7FFBDD83FDE7A3FFF5DEFBE4AAEFB538C5BFB2C0C0C0C0
        C0C0C77113C87218C18A53C0C0C0C1B9AFCB7B24DFA043F3CB6DF2C65CF2C759
        F4C960F4CC67F7D16EF7D573F8D778FBE098FFEFCDFEF0D4F4CE6EEFB63BC5BF
        B2C0C0C0C0C0C0C0C0C0BF6918C1AA93C0C0C0C0C0C0C0C0C0C0C0C0CA9D65D4
        8321E9BB6AF3D085F8DF99FBE5A9FCE5ABFEEBBCFFF3D8FAE3AFF4CF79EFB438
        DFBB6DC0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0BAB4C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0CAAD84D59E51DE952CE1982BEDB95BE7A938E8A934E3
        B253D8BA7BC2C0BCC0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0}
      OnClick = ModificarClick
    end
    object Sair: TSpeedButton
      Left = 948
      Top = 6
      Width = 121
      Height = 30
      Caption = 'SAIR'
      Glyph.Data = {
        F6060000424DF606000000000000360000002800000018000000180000000100
        180000000000C0060000120B0000120B00000000000000000000C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0BFBFBFBFBFBFBFBFBFBFBFBFC0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0BBBBBBB3B3
        B3AFAFAFB9B9B9C0C0C0C0C0C0B1B1B198989897979797979797979797979795
        9595959595959595959595959595959595959595959595959595959595959595
        989899868B8F667682617B8F94979AC0C0C0C0C0C09D9D9D7979797575757878
        787373725B5F635B5D5F5E5C5C5D5C5C5D5C5C5D5C5C5D5C5C5D5C5C5D5C5C5E
        5C595C5E60516A7D4D74914E7FA64F84AF6BABDF868F95C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C063717F69778477706A71706F71706F71706F7170
        6F71706F717070756D666A757E518CBB518CBB4F85B14C7EA6649DCB888F94C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C067727E64707A6C655F676564
        6765646765646765646765646765656A625B616B744C84B14D85B14D81AD4F81
        AA68A1CF878E94C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C06E768363
        6E796A625C656362656362656362656362656362656363685F58606A724F87B4
        4E87B44E84AF5185AD6CA3D0878E94C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0BFBF
        BF9A9D9B4E6B7663697866605A62616063616063616063616063616063616165
        5C565F68715189B75089B84F86B25488B16FA5D2878D93C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C088908C22945C2A8681685A76695A58615E5E605E5D605E5D605E
        5D605E5D605E5E6259525E6770528BB9538BBA5087B4578BB472A8D4868D93C0
        C0C0C0C0C0C0C0C0BFBFBF8A908C1DA27200D687227C6D58505C5A564D5D5B5C
        5E5C5B5D5B5B5D5B5B5D5B5B5D5B5C5F56505B656E548EBB538EBE5386B35980
        A575A8D3868D92C0C0C0C0C0C0BEBEBE89918C1C996A00E1A400D19604A6690C
        AF71119D614E60555E57585A59585A59585A59585A59595B534D59636C558EBF
        578EBD4E8DBD4898C477ACD7868C92C0C0C0C0C0C0979C991E9B6D00D69E00D2
        9F00CF9B00D49A17E7B71CC486495E4E5B505458565658565658565658565758
        504A58626B5692C25E8CBA3D9FD44AA4D67DAFD7868C91C0C0C0C0C0C0808E86
        15C98E1FDAB502C59602C79804C3922ADBB532C08C485C4E5850525655545655
        54565554565555564E4856616A5794C4608EBC3AA3DA5293BE81ADD5858C91C0
        C0C0C0C0C0A9ABAA438C6E29CCA029D2B13AD1B22BD5B14BE9CB3EC591435B4A
        554C4F545252545252545252545253534A45545F695994C66091C1439CD247A8
        D980B3DA858B91C0C0C0C0C0C0C0C0C0B8B8B84D8C703DD3B165D6BC26946624
        8A5D24805348544E534C4E504F4F504F4F504F4F5050504F4642535E675B97C8
        5C98C95690BE62A3D185B5DC858B90C0C0C0C0C0C0C0C0C0C0C0C0BBBBBB5290
        791BBF852B857E53415B533D3F514C4E4E4D4D4E4D4D4E4D4D4E4D4D4E4E4E4C
        443F515C655D99CB5C9ACC5690C16C9DC888B5DC848B8FC0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0B5B7B65C9878398A845551674D45404B4A4B4C4A4A4C4A4A4C4A
        4A4C4A4A4C4B4B4A413B505B645E9BCD5E9CCE5792C56DA2CF8AB8DC848A8FC0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C06A7A875057684A433E494849
        494848494848494848494848494949463F394E59635F9ECF609FD05795C670A4
        D18DBADE848A8FC0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C06F79864C
        5A65463F3B464546464545464545464545464545464646453C364854605999CF
        609FD35A97C972A8D490BADF83898EC0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C067778249525A43352A433B36433B35433B35433B35433B35433C363B
        2E2355585A7FB5E460A2DA5091C774ABD893BCDF83898EC0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C08891985F86A7577A97597C99597C99597C99597C
        99597C995A7C995275916285A09CB8D0A1C8EA67A4D66BA6D794BDDF83898EC0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0BBBCBDB5BBBFB4BABFB4BABE
        B4BABEB4BABEB4BABEB4BABEB4BABEB3B9BEB6BBC0B4B6B7A0A2A4B6CFE5A9D1
        F397BEDF83888EC0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0B8BABBB7BEC5A0C3DF898E92C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0}
      OnClick = SairClick
    end
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1100
    Height = 531
    ActivePage = TabDados
    Align = alClient
    TabOrder = 1
    object TabDados: TTabSheet
      Caption = 'Dados do Empresa'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupDadosEmpresa: TGroupBox
        Left = 30
        Top = 24
        Width = 1035
        Height = 449
        Caption = 'Dados do Empresa'
        TabOrder = 0
        object GroupGenericas: TGroupBox
          Left = 30
          Top = 34
          Width = 515
          Height = 383
          TabOrder = 0
          object Label5: TLabel
            Left = 13
            Top = 11
            Width = 92
            Height = 18
            Caption = 'Nome Fantasia'
          end
          object Label4: TLabel
            Left = 13
            Top = 68
            Width = 75
            Height = 18
            Caption = 'Raz'#227'o Social'
          end
          object Label9: TLabel
            Left = 13
            Top = 122
            Width = 30
            Height = 18
            Caption = 'CNPJ'
          end
          object Label1: TLabel
            Left = 13
            Top = 181
            Width = 109
            Height = 18
            Caption = 'Inscri'#231#227'o Estadual'
          end
          object Label10: TLabel
            Left = 237
            Top = 181
            Width = 118
            Height = 18
            Caption = 'Inscri'#231#227'o Municipal'
          end
          object Label2: TLabel
            Left = 14
            Top = 242
            Width = 55
            Height = 18
            Caption = 'Telefone'
          end
          object Label18: TLabel
            Left = 237
            Top = 242
            Width = 39
            Height = 18
            Caption = 'E-Mail'
          end
          object Label6: TLabel
            Left = 14
            Top = 301
            Width = 24
            Height = 18
            Caption = 'Site'
          end
          object EditNome: TEdit
            Left = 13
            Top = 31
            Width = 484
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 0
          end
          object EditRazaoSocial: TEdit
            Left = 13
            Top = 92
            Width = 484
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 1
          end
          object EditCnpj: TEdit
            Left = 13
            Top = 146
            Width = 484
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 2
          end
          object EditInscricaoEstadual: TEdit
            Left = 13
            Top = 205
            Width = 205
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 3
          end
          object EditInscricaoMunicipal: TEdit
            Left = 237
            Top = 205
            Width = 260
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 4
          end
          object EditTelefone: TEdit
            Left = 13
            Top = 266
            Width = 205
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 5
          end
          object EditEmail: TEdit
            Left = 237
            Top = 266
            Width = 260
            Height = 26
            CharCase = ecLowerCase
            Color = clGradientInactiveCaption
            TabOrder = 6
          end
          object EditSite: TEdit
            Left = 14
            Top = 325
            Width = 483
            Height = 26
            CharCase = ecLowerCase
            Color = clGradientInactiveCaption
            TabOrder = 7
          end
        end
        object GroupEnderecos: TGroupBox
          Left = 560
          Top = 34
          Width = 458
          Height = 383
          TabOrder = 1
          object Label15: TLabel
            Left = 14
            Top = 95
            Width = 23
            Height = 18
            Caption = 'CEP'
          end
          object Label17: TLabel
            Left = 182
            Top = 95
            Width = 65
            Height = 18
            Caption = 'Cidade/UF'
          end
          object Label14: TLabel
            Left = 14
            Top = 160
            Width = 70
            Height = 18
            Caption = 'Logradouro'
          end
          object Label16: TLabel
            Left = 14
            Top = 224
            Width = 51
            Height = 18
            Caption = 'N'#250'mero'
          end
          object Label27: TLabel
            Left = 166
            Top = 224
            Width = 37
            Height = 18
            Caption = 'Bairro'
          end
          object Label19: TLabel
            Left = 14
            Top = 28
            Width = 107
            Height = 18
            Caption = 'Tipo de Endere'#231'o'
          end
          object Label26: TLabel
            Left = 14
            Top = 297
            Width = 89
            Height = 18
            Caption = 'Complemento'
          end
          object EditEnderecosCep: TEdit
            Left = 14
            Top = 119
            Width = 153
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 1
          end
          object ComboEnderecosRegiao: TComboBox
            Left = 182
            Top = 119
            Width = 262
            Height = 26
            Style = csDropDownList
            ItemIndex = 0
            TabOrder = 2
            Text = 'Pessoa Jur'#237'dica'
            Items.Strings = (
              'Pessoa Jur'#237'dica'
              'Pessoa F'#237'sica')
          end
          object EditEnderecosLogradouro: TEdit
            Left = 14
            Top = 184
            Width = 430
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 3
          end
          object EditEnderecosNumero: TEdit
            Left = 14
            Top = 248
            Width = 123
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 4
          end
          object EditEnderecosBairro: TEdit
            Left = 166
            Top = 248
            Width = 278
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 5
          end
          object ComboEnderecosTipo: TComboBox
            Left = 14
            Top = 52
            Width = 430
            Height = 26
            Style = csDropDownList
            ItemIndex = 0
            TabOrder = 0
            Text = 'Pessoa Jur'#237'dica'
            Items.Strings = (
              'Pessoa Jur'#237'dica'
              'Pessoa F'#237'sica')
          end
          object EditEnderecosComplemento: TEdit
            Left = 14
            Top = 322
            Width = 430
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 6
          end
        end
      end
    end
  end
end
