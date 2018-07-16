object FClientesView: TFClientesView
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Ficha Cadastral de Clientes'
  ClientHeight = 562
  ClientWidth = 1010
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
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1010
    Height = 514
    ActivePage = TabBancarias
    Align = alClient
    TabOrder = 0
    OnChange = PageControl1Change
    object TabDados: TTabSheet
      Caption = 'Dados do Cliente'
      object GroupDadosCliente: TGroupBox
        Left = 30
        Top = 24
        Width = 955
        Height = 425
        Caption = 'Dados do Cliente'
        TabOrder = 0
        object GroupJuridica: TGroupBox
          Left = 479
          Top = 260
          Width = 459
          Height = 145
          TabOrder = 3
          object Label9: TLabel
            Left = 19
            Top = 76
            Width = 30
            Height = 18
            Caption = 'CNPJ'
          end
          object Label4: TLabel
            Left = 17
            Top = 15
            Width = 75
            Height = 18
            Caption = 'Raz'#227'o Social'
          end
          object Label10: TLabel
            Left = 229
            Top = 76
            Width = 118
            Height = 18
            Caption = 'Inscri'#231#227'o Municipal'
          end
          object EditCnpj: TEdit
            Left = 17
            Top = 100
            Width = 191
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 1
          end
          object EditRazaoSocial: TEdit
            Left = 17
            Top = 39
            Width = 432
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 0
          end
          object EditInscricaoMunicipal: TEdit
            Left = 227
            Top = 100
            Width = 222
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 2
          end
        end
        object GroupFisica: TGroupBox
          Left = 479
          Top = 260
          Width = 459
          Height = 145
          TabOrder = 2
          object Label11: TLabel
            Left = 17
            Top = 15
            Width = 23
            Height = 18
            Caption = 'CPF'
          end
          object Label12: TLabel
            Left = 233
            Top = 15
            Width = 17
            Height = 18
            Caption = 'RG'
          end
          object Label13: TLabel
            Left = 17
            Top = 75
            Width = 124
            Height = 18
            Caption = 'Data de Nascimento'
          end
          object EditCpf: TEdit
            Left = 15
            Top = 39
            Width = 204
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 0
          end
          object EditRg: TEdit
            Left = 231
            Top = 39
            Width = 218
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 1
          end
          object DateNascimento: TDateTimePicker
            Left = 17
            Top = 96
            Width = 202
            Height = 26
            Date = 43124.506019745370000000
            Time = 43124.506019745370000000
            TabOrder = 2
          end
        end
        object GroupGenericas: TGroupBox
          Left = 24
          Top = 26
          Width = 433
          Height = 383
          TabOrder = 0
          object Label7: TLabel
            Left = 13
            Top = 252
            Width = 128
            Height = 18
            Caption = 'Tipo de Contribuinte'
          end
          object Label5: TLabel
            Left = 13
            Top = 139
            Width = 38
            Height = 18
            Caption = 'Nome'
          end
          object Label18: TLabel
            Left = 13
            Top = 191
            Width = 39
            Height = 18
            Caption = 'E-Mail'
          end
          object Label6: TLabel
            Left = 13
            Top = 310
            Width = 24
            Height = 18
            Caption = 'Site'
          end
          object EditSite: TEdit
            Left = 13
            Top = 332
            Width = 404
            Height = 26
            CharCase = ecLowerCase
            Color = clGradientInactiveCaption
            TabOrder = 7
          end
          object ComboTipoContribuinte: TComboBox
            Left = 13
            Top = 276
            Width = 404
            Height = 26
            Style = csDropDownList
            ItemIndex = 0
            TabOrder = 6
            Text = 'Pessoa Jur'#237'dica'
            Items.Strings = (
              'Pessoa Jur'#237'dica'
              'Pessoa F'#237'sica')
          end
          object EditEmail: TEdit
            Left = 13
            Top = 215
            Width = 404
            Height = 26
            CharCase = ecLowerCase
            Color = clGradientInactiveCaption
            TabOrder = 5
          end
          object EditNome: TEdit
            Left = 13
            Top = 159
            Width = 404
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 4
          end
          object ComboIndicacao: TComboBox
            Left = 13
            Top = 43
            Width = 404
            Height = 26
            Style = csDropDownList
            ItemIndex = 0
            TabOrder = 1
            Text = 'Pessoa Jur'#237'dica'
            Items.Strings = (
              'Pessoa Jur'#237'dica'
              'Pessoa F'#237'sica')
          end
          object ComboGrupo: TComboBox
            Left = 13
            Top = 105
            Width = 404
            Height = 26
            Style = csDropDownList
            ItemIndex = 0
            TabOrder = 3
            Text = 'Pessoa Jur'#237'dica'
            Items.Strings = (
              'Pessoa Jur'#237'dica'
              'Pessoa F'#237'sica')
          end
          object CheckIndicacao: TCheckBox
            Left = 13
            Top = 20
            Width = 84
            Height = 17
            Caption = 'Indica'#231#227'o'
            TabOrder = 0
            OnClick = CheckIndicacaoClick
          end
          object CheckGrupo: TCheckBox
            Left = 13
            Top = 82
            Width = 84
            Height = 17
            Caption = 'Grupo'
            TabOrder = 2
            OnClick = CheckGrupoClick
          end
        end
        object GroupDados: TGroupBox
          Left = 479
          Top = 73
          Width = 458
          Height = 181
          TabOrder = 1
          object Label1: TLabel
            Left = 238
            Top = 63
            Width = 120
            Height = 18
            Caption = 'Telefone Comercial'
          end
          object Label2: TLabel
            Left = 12
            Top = 63
            Width = 102
            Height = 18
            Caption = 'Telefone Celular'
          end
          object Label3: TLabel
            Left = 238
            Top = 115
            Width = 109
            Height = 18
            Caption = 'Inscri'#231#227'o Estadual'
          end
          object Label63: TLabel
            Left = 237
            Top = 8
            Width = 94
            Height = 18
            Caption = 'Tipo de Cliente'
          end
          object Label66: TLabel
            Left = 11
            Top = 8
            Width = 52
            Height = 18
            Caption = 'Situa'#231#227'o'
          end
          object Label8: TLabel
            Left = 11
            Top = 115
            Width = 23
            Height = 18
            Caption = 'FAX'
          end
          object ComboSituacao: TComboBox
            Left = 11
            Top = 32
            Width = 221
            Height = 26
            Style = csDropDownList
            ItemIndex = 0
            TabOrder = 0
            Text = 'Pessoa F'#237'sica'
            Items.Strings = (
              'Pessoa F'#237'sica'
              'Pessoa Jur'#237'dica')
          end
          object ComboTipo: TComboBox
            Left = 238
            Top = 32
            Width = 211
            Height = 26
            Style = csDropDownList
            ItemIndex = 0
            TabOrder = 1
            Text = 'Pessoa F'#237'sica'
            OnChange = ComboTipoChange
            Items.Strings = (
              'Pessoa F'#237'sica'
              'Pessoa Jur'#237'dica')
          end
          object EditFax: TEdit
            Left = 12
            Top = 137
            Width = 220
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 4
          end
          object EditInscricaoEstadual: TEdit
            Left = 238
            Top = 87
            Width = 211
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 3
          end
          object EditTelefoneCelular: TEdit
            Left = 11
            Top = 87
            Width = 221
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 2
          end
          object EditTelefoneComercial: TEdit
            Left = 238
            Top = 137
            Width = 211
            Height = 26
            CharCase = ecUpperCase
            Color = clGradientInactiveCaption
            TabOrder = 5
          end
        end
        object GroupTipo: TGroupBox
          Left = 479
          Top = 26
          Width = 459
          Height = 41
          TabOrder = 4
          object CheckCliente: TCheckBox
            Left = 16
            Top = 13
            Width = 97
            Height = 17
            Caption = 'Cliente'
            TabOrder = 0
          end
          object CheckFornecedor: TCheckBox
            Left = 96
            Top = 13
            Width = 97
            Height = 17
            Caption = 'Fornecedor'
            TabOrder = 1
          end
        end
      end
    end
    object TabEnderecos: TTabSheet
      Caption = 'Endere'#231'os'
      ImageIndex = 1
      object Panel6: TPanel
        Left = 0
        Top = 0
        Width = 1002
        Height = 153
        Align = alTop
        Color = clMenu
        ParentBackground = False
        TabOrder = 0
        object Label21: TLabel
          Left = 471
          Top = 10
          Width = 70
          Height = 18
          Caption = 'Logradouro'
        end
        object Label22: TLabel
          Left = 14
          Top = 10
          Width = 23
          Height = 18
          Caption = 'CEP'
        end
        object Label23: TLabel
          Left = 920
          Top = 10
          Width = 51
          Height = 18
          Caption = 'N'#250'mero'
        end
        object Label25: TLabel
          Left = 182
          Top = 10
          Width = 65
          Height = 18
          Caption = 'Cidade/UF'
        end
        object Label24: TLabel
          Left = 471
          Top = 74
          Width = 107
          Height = 18
          Caption = 'Tipo de Endere'#231'o'
        end
        object Label28: TLabel
          Left = 680
          Top = 74
          Width = 89
          Height = 18
          Caption = 'Complemento'
        end
        object Label20: TLabel
          Left = 14
          Top = 74
          Width = 37
          Height = 18
          Caption = 'Bairro'
        end
        object EditEnderecosLogradouro: TEdit
          Left = 471
          Top = 34
          Width = 437
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 2
        end
        object EditEnderecosCep: TEdit
          Left = 14
          Top = 34
          Width = 153
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 0
        end
        object EditEnderecosNumero: TEdit
          Left = 920
          Top = 34
          Width = 76
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 3
        end
        object ComboEnderecosRegiao: TComboBox
          Left = 182
          Top = 34
          Width = 267
          Height = 26
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 1
          Text = 'Pessoa Jur'#237'dica'
          Items.Strings = (
            'Pessoa Jur'#237'dica'
            'Pessoa F'#237'sica')
        end
        object ComboEnderecosTipo: TComboBox
          Left = 471
          Top = 98
          Width = 195
          Height = 26
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 5
          Text = 'Pessoa Jur'#237'dica'
          Items.Strings = (
            'Pessoa Jur'#237'dica'
            'Pessoa F'#237'sica')
        end
        object EditEnderecosComplemento: TEdit
          Left = 680
          Top = 98
          Width = 316
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 6
        end
        object EditEnderecosBairro: TEdit
          Left = 14
          Top = 98
          Width = 435
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 4
        end
      end
      object StringGridEnderecos: TStringGrid
        Left = 0
        Top = 153
        Width = 1002
        Height = 270
        Align = alClient
        TabOrder = 1
        OnDrawCell = StringGridEnderecosDrawCell
        OnMouseDown = StringGridEnderecosMouseDown
        OnSelectCell = StringGridEnderecosSelectCell
        ColWidths = (
          64
          64
          64
          64
          64)
        RowHeights = (
          24
          24
          24
          24
          24)
      end
      object Panel7: TPanel
        Left = 0
        Top = 423
        Width = 1002
        Height = 58
        Align = alBottom
        Color = clMenu
        ParentBackground = False
        TabOrder = 2
        object ButtonAdicionarEndereco: TButton
          Left = 14
          Top = 15
          Width = 116
          Height = 29
          Caption = 'ADICIONAR'
          TabOrder = 0
          OnClick = ButtonAdicionarEnderecoClick
        end
        object ButtonRemoverEndereco: TButton
          Left = 149
          Top = 15
          Width = 116
          Height = 29
          Caption = 'REMOVER'
          TabOrder = 1
          OnClick = ButtonRemoverEnderecoClick
        end
      end
    end
    object TabContatos: TTabSheet
      Caption = 'Contatos'
      ImageIndex = 2
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 1002
        Height = 137
        Align = alTop
        Color = clMenu
        ParentBackground = False
        TabOrder = 0
        object Label41: TLabel
          Left = 14
          Top = 14
          Width = 38
          Height = 18
          Caption = 'Nome'
        end
        object Label42: TLabel
          Left = 280
          Top = 66
          Width = 49
          Height = 18
          Caption = 'Contato'
        end
        object Label43: TLabel
          Left = 544
          Top = 10
          Width = 35
          Height = 18
          Caption = 'Cargo'
        end
        object Label14: TLabel
          Left = 544
          Top = 70
          Width = 72
          Height = 18
          Caption = 'Observa'#231#227'o'
        end
        object Label15: TLabel
          Left = 14
          Top = 67
          Width = 98
          Height = 18
          Caption = 'Tipo de Contato'
        end
        object EditContatosNome: TEdit
          Left = 14
          Top = 34
          Width = 499
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 0
        end
        object EditContatosContato: TEdit
          Left = 280
          Top = 90
          Width = 233
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 3
        end
        object EditContatosCargo: TEdit
          Left = 544
          Top = 34
          Width = 441
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 1
        end
        object EditContatosObservacao: TEdit
          Left = 544
          Top = 90
          Width = 441
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 4
        end
        object ComboContatosTipo: TComboBox
          Left = 14
          Top = 90
          Width = 251
          Height = 26
          Style = csDropDownList
          ItemIndex = 0
          TabOrder = 2
          Text = 'Pessoa Jur'#237'dica'
          Items.Strings = (
            'Pessoa Jur'#237'dica'
            'Pessoa F'#237'sica')
        end
      end
      object StringGridContatos: TStringGrid
        Left = 0
        Top = 137
        Width = 1002
        Height = 286
        Align = alClient
        TabOrder = 1
        OnDrawCell = StringGridContatosDrawCell
        OnMouseDown = StringGridContatosMouseDown
        OnSelectCell = StringGridContatosSelectCell
        ColWidths = (
          64
          64
          64
          64
          64)
        RowHeights = (
          24
          24
          24
          24
          24)
      end
      object Panel5: TPanel
        Left = 0
        Top = 423
        Width = 1002
        Height = 58
        Align = alBottom
        Color = clMenu
        ParentBackground = False
        TabOrder = 2
        object ButtonAdicionarContato: TButton
          Left = 14
          Top = 15
          Width = 116
          Height = 29
          Caption = 'ADICIONAR'
          TabOrder = 0
          OnClick = ButtonAdicionarContatoClick
        end
        object ButtonRemoverContato: TButton
          Left = 149
          Top = 15
          Width = 116
          Height = 29
          Caption = 'REMOVER'
          TabOrder = 1
          OnClick = ButtonRemoverContatoClick
        end
      end
    end
    object TabBancarias: TTabSheet
      Caption = 'Refer'#234'ncias Banc'#225'rias'
      ImageIndex = 3
      object StringGridBancarias: TStringGrid
        Left = 0
        Top = 137
        Width = 1002
        Height = 286
        Align = alClient
        TabOrder = 0
        OnDrawCell = StringGridBancariasDrawCell
        OnMouseDown = StringGridBancariasMouseDown
        OnSelectCell = StringGridBancariasSelectCell
        ColWidths = (
          64
          64
          64
          64
          64)
        RowHeights = (
          24
          24
          24
          24
          24)
      end
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 1002
        Height = 137
        Align = alTop
        Color = clMenu
        ParentBackground = False
        TabOrder = 1
        object Label16: TLabel
          Left = 22
          Top = 10
          Width = 59
          Height = 18
          Caption = 'Descri'#231#227'o'
        end
        object Label17: TLabel
          Left = 22
          Top = 65
          Width = 37
          Height = 18
          Caption = 'Banco'
        end
        object Label19: TLabel
          Left = 333
          Top = 65
          Width = 36
          Height = 18
          Caption = 'Conta'
        end
        object Agencia: TLabel
          Left = 333
          Top = 10
          Width = 49
          Height = 18
          Caption = 'Ag'#234'ncia'
        end
        object Label26: TLabel
          Left = 653
          Top = 65
          Width = 59
          Height = 18
          Caption = 'CPF/CNPJ'
        end
        object Label27: TLabel
          Left = 653
          Top = 10
          Width = 38
          Height = 18
          Caption = 'Nome'
        end
        object EditBancariasDescricao: TEdit
          Left = 22
          Top = 34
          Width = 285
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 0
        end
        object EditBancariasBanco: TEdit
          Left = 22
          Top = 86
          Width = 285
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 1
        end
        object EditBancariasAgencia: TEdit
          Left = 333
          Top = 34
          Width = 300
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 2
        end
        object EditBancariasConta: TEdit
          Left = 333
          Top = 86
          Width = 300
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 3
        end
        object EditBancariasCpfCnpj: TEdit
          Left = 653
          Top = 89
          Width = 332
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 5
        end
        object EditBancariasNome: TEdit
          Left = 653
          Top = 34
          Width = 332
          Height = 26
          CharCase = ecUpperCase
          Color = clGradientInactiveCaption
          TabOrder = 4
        end
      end
      object Panel4: TPanel
        Left = 0
        Top = 423
        Width = 1002
        Height = 58
        Align = alBottom
        Color = clMenu
        ParentBackground = False
        TabOrder = 2
        object ButtonAdicionarBancarias: TButton
          Left = 14
          Top = 15
          Width = 116
          Height = 29
          Caption = 'ADICIONAR'
          TabOrder = 0
          OnClick = ButtonAdicionarBancariasClick
        end
        object ButtonRemoverBancarias: TButton
          Left = 149
          Top = 15
          Width = 116
          Height = 29
          Caption = 'REMOVER'
          TabOrder = 1
          OnClick = ButtonRemoverBancariasClick
        end
      end
    end
    object TabFinanceiro: TTabSheet
      Caption = 'Informa'#231#245'es Financeiras'
      ImageIndex = 4
      object BoxFinanceiro: TGroupBox
        Left = 272
        Top = 147
        Width = 490
        Height = 158
        Caption = 'Informa'#231#245'es Financeiras'
        TabOrder = 0
        object Label51: TLabel
          Left = 56
          Top = 84
          Width = 67
          Height = 18
          Caption = 'Limite (R$)'
        end
        object EditFinanceiroLimite: TEdit
          Left = 129
          Top = 81
          Width = 336
          Height = 26
          CharCase = ecUpperCase
          Color = clMoneyGreen
          MaxLength = 8
          TabOrder = 1
        end
        object CheckFinanceiroConsumidor: TCheckBox
          Left = 56
          Top = 47
          Width = 140
          Height = 17
          Caption = 'Cliente Consumidor'
          TabOrder = 0
        end
      end
    end
  end
  object PanelOptions: TPanel
    Left = 0
    Top = 514
    Width = 1010
    Height = 48
    Align = alBottom
    TabOrder = 1
    object Modificar: TSpeedButton
      Left = 299
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
    object Adicionar: TSpeedButton
      Left = 25
      Top = 10
      Width = 121
      Height = 30
      Caption = 'ADICIONAR'
      Glyph.Data = {
        F6060000424DF606000000000000360000002800000018000000180000000100
        180000000000C0060000120B0000120B00000000000000000000C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0B2B4B26E776F464F47
        444D45454F45454F45454F45414D41575E57A4A4A4C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C08C
        A18C33823645A54D43A24A42A04941A04945A64C35933B274627A0A0A0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C091A091549B5A3DC4491EAF291FA6281DA4252BB43356B85F2C
        472CA0A0A0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C091A19150975422B22E009D09009407008C
        040D97114AAC522C492DA0A0A0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C091A49150975528B635
        08A71309A01305960E109B194CAC542C492DA1A1A1C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C094
        9D9450955528B83407A71309A414069E1010A11A4CAC532E4A2FA5A5A5C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0A4A4A49F9F9FA0A0
        A0A0A0A0AAAAAA7D7D7D4C8E5128BB3407A81309A61507A41212A81C4BAC532B
        432B8B8B8BA4A4A4A1A1A1A0A0A0A0A0A0A0A0A0A5A5A5C0C0C0C0C0C0566B56
        2F482F2C452C2C462C2C472C324C33233A23478C4B2ABA3607A81309A71506A6
        1313AD1F50AD58113D112B452B2E4A2F2D492E2C492E2C472C2A482A585F58C0
        C0C0C0C0C01F72245EB96658B25F57B25F4FAF5849AD514AAA5161BC6922B12D
        06A61209A71507A6130FAA1B57BF6151AD574BAC534CAC534CAC544AAB5357B6
        5E35933B3F4B3FC0C0C0C0C0C02C7E3083DE8B76D27D71D27A59C96327B7330F
        AE1B0FAB1B0BA81709A71509A71509A71508A7140EAA1B13AD1F12A91C11A31B
        109C190F97112AB23245A64D454E45C0C0C0C0C0C02C7C3283D98A78CE7D72CD
        796DCC7558C46127B13205A51104A61009A71509A71509A71509A71507A61306
        A61307A512059F1104980F008D031CA52542A049454F45C0C0C0C0C0C02D7C31
        87DB8D7FD08578CF7E74CD7B72CD7968C96E3FBB4714AB1F06A61208A71408A7
        1409A71509A71509A71509A71509A51509A2140096091FA82842A049454F45C0
        C0C0C0C0C02C7C318EE0968BD69183D4897FD28578D17E74CF7B6ECD7556C25E
        2CB4370FA91A07A61307A61305A61207A81307A81307A81308A814009E0A1EAF
        2943A24A454E45C0C0C0C0C0C026792C8FE1988CD99386D88D83D58A7FD58579
        D48175D07D70CC7769C9704DBF5529B23412AB1D22B12E2ABA3528B93428B634
        29B73522B22D3DC44946A44D444E44C0C0C0C0C0C02A712D4D975349934E4A93
        4E4A934F4C9451458A4959AD6174D07D71CE786ECB7464C76A52C45A66BF6F45
        8B4A4D9051519655509654509654549C593583396C756DC0C0C0C0C0C094A594
        91A09191A09191A09191A09194A2946F836F438B467DD48477D17E6FCC766BCB
        7270D17755AE5C2435247C847C92A49291A19191A09191A0918FA28FB2B4B3C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C09BA79B4D945183D68A
        7FD38676CE7D71CD7871D17857B25F324632AEAFAEC0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C090
        9F904A934E87D88F86D68D7ED18479CF7F77D48057B35F2C462CA0A0A0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C091A09149934E8CDA938DD99485D38B80D2857FD68558B3612C
        462CA0A0A0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C091A09149934D94DC9B99DB9D8FD69489D4
        8F87D98C5AB3612C452CA0A0A0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0909F904D985193E39C
        96E29C8FDE968CDD938EE39560BA682F482FA4A4A4C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C093
        A4932F7333287A2F2C7B312C7B302C7B302C7E31237528546954BEBEBEC0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0}
      OnClick = AdicionarClick
    end
    object Deletar: TSpeedButton
      Left = 160
      Top = 10
      Width = 121
      Height = 30
      Caption = 'DELETAR'
      Glyph.Data = {
        F6060000424DF606000000000000360000002800000018000000180000000100
        180000000000C0060000120B0000120B00000000000000000000C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C09C9C9D808081A4A4A4C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0A4A4A58282839F9F9FBEBEBEC0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C09797994040642A2A4466
        6666A8A8A8C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0A5A5A74B4B68292946
        5B5B5BA0A0A0BFBFBFC0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C09696963E3D
        63413CC633319B272835646464A6A6A6C0C0C0C0C0C0C0C0C0C0C0C0A7A7A749
        4864403CB9403DAB2424365A5A5AA0A0A0BFBFBFC0C0C0C0C0C0C0C0C0C0C0C0
        9A9A9A3B3B5D322EBB100DCF1C18CF2D2A8F242430666666A9A9A9C0C0C0C0C0
        C0AAAAAB4546633532B01D18D8201DDB35329B20202E5C5C5CA0A0A0BDBDBDC0
        C0C0C0C0C0A0A0A24242682F2CBB110FCA0000AA0000B51D19CE282688272832
        6A6A6AAFAFAFACACAC4B4B633430AC1E1AD80000B80000B21C1ACC2E2C962323
        375E5E5FA9A9A9C0C0C0C0C0C05F5F7C4643B41E19E20000B20500B50000B000
        00B71E1AD12F2D8E2C2D3769696949495F3A35AB211BD90000BE0100B30200A8
        0000A52926DA2C298A464652ACACACC0C0C0C0C0C08E8EA142408E3832D30907
        CC0000BE0600C00300BB0201C6302BDC323183262648403CA42923DC0100C703
        00BB0400B10000A50505B32622BF36366D909093BEBEBEC0C0C0C0C0C0C0C0C0
        8E8E9F423F93433CE00C0AD50000CA0800CB0300C90906D43530D5504CC22D26
        DB0502CF0400C50500BC0000B00907BE2A26C8343268919192C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C08E8FA0484594453FDA0F0DDE0100D00A00D30500D2
        1007DA2117E10902D60600CE0700C80100BC0B09C42623BA363468919192C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C09192A44F4D984942DB0F
        0CDD0500D40B00D70900D70700D70900D50800D10300C90F0BCA2925B7363560
        949494C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C08F8F95504F8C4B45DD0C0ADD0400D60A00D70A00D70A00D50600D1120CD330
        2CB9282851848484C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0AFAFAF59596D7D79DB3531E80905D70701D60700D70800
        D60500D42019DB44419F262630717171ABABABC0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0A9A9AB57576F7E7BC88D87F26760E7524BE3
        352DDE1F17DA1209D80905D40A05D42923D62F2D87282934696969A7A7A7C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0A6A6A75353718785D3958FFA6E
        68E96F69E7726CE86B66E7655FE8544EE3443DE13129DB261EDB4842E746459B
        2A2A37636363A7A7A7C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0A9A9AB5454748D8A
        D99692FA746EEA746DE7736DE86B64E67F7AEF9590F3756FEC6761E66761E65C
        56E3574FE6736DF65D5BAA2A2B39676767A9A9A9BEBEBEC0C0C0C0C0C0ACACAF
        5958738C89D49E99FC7872E97973E97A74E9716BE78882F48B87DB706FAB8E8B
        E4726BEE625CE5655EE55B55E25850E67973F75A59A72C2D3F676768ACACACC0
        C0C0C0C0C06A6A85908ED1A4A0FF7C77E97E79EA7E79EA7570E78983F59D9AF1
        51517973737E6766999792EE716AED635DE56762E65D58E3544DE48883FF5F5E
        AC464656AAAAAAC0C0C0C0C0C086869F807FBBABA5FF7D78EB837EEA7A75E88E
        89F6A39EF8595984949496C0C0C09393A36967A29B97F4736CEE6660E5635DE4
        605BEB908BF95B5A9384848ABDBDBDC0C0C0C0C0C0BFBFBF83839C8280BDAAA6
        FF7F7BEB918CF6AAA4FB5D5C86919193C0C0C0C0C0C0C0C0C08D8DA16C6AA999
        96F3706AEC6B63EE938EF95F5E94848488BFBFBFC0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C086869D7A78BAB6B1FFA7A2F8595885939399C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C09090A36868A29E98F69B96FE615F94838387BFBFBFC0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0BFBFC086869E716EB15E5D88959696C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C09090A36664A46361938A8A8EBFBFBFC0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0BDBDBE9999A9A0A0A8C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0BFBFC09C9CAA9D9DA7
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0}
      OnClick = DeletarClick
    end
    object Sair: TSpeedButton
      Left = 828
      Top = 10
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
  object RecursosThread: TTimer
    Enabled = False
    Interval = 50
    OnTimer = RecursosThreadTimer
    Left = 856
    Top = 400
  end
end
