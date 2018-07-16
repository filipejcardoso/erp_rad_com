object FLinkarAplicativos: TFLinkarAplicativos
  Left = 0
  Top = 0
  Caption = 'Linkar Aplicativos'
  ClientHeight = 425
  ClientWidth = 884
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
  object Label1: TLabel
    Left = 73
    Top = 144
    Width = 33
    Height = 18
    Caption = 'HOST'
  end
  object Label2: TLabel
    Left = 47
    Top = 179
    Width = 59
    Height = 18
    Caption = 'NOME BD'
  end
  object Label3: TLabel
    Left = 30
    Top = 216
    Width = 76
    Height = 18
    Caption = 'USUARIO BD'
  end
  object Label4: TLabel
    Left = 44
    Top = 252
    Width = 62
    Height = 18
    Caption = 'SENHA BD'
  end
  object Label5: TLabel
    Left = 469
    Top = 155
    Width = 84
    Height = 18
    Caption = 'FORNECEDOR'
  end
  object Label7: TLabel
    Left = 497
    Top = 187
    Width = 56
    Height = 18
    Caption = 'USU'#193'RIO'
  end
  object Label8: TLabel
    Left = 440
    Top = 219
    Width = 113
    Height = 18
    Caption = 'CENTRO DE CUSTO'
  end
  object Label9: TLabel
    Left = 498
    Top = 251
    Width = 55
    Height = 18
    Caption = 'PROJETO'
  end
  object Label10: TLabel
    Left = 446
    Top = 283
    Width = 107
    Height = 18
    Caption = 'CONTA CONT'#193'BIL'
  end
  object EditHost: TEdit
    Left = 112
    Top = 141
    Width = 297
    Height = 26
    TabOrder = 0
  end
  object EditNome: TEdit
    Left = 112
    Top = 176
    Width = 297
    Height = 26
    TabOrder = 1
  end
  object EditUsuarioBd: TEdit
    Left = 112
    Top = 210
    Width = 297
    Height = 26
    TabOrder = 2
  end
  object EditSenhaBd: TEdit
    Left = 112
    Top = 249
    Width = 297
    Height = 26
    PasswordChar = '*'
    TabOrder = 3
  end
  object ComboFornecedor: TComboBox
    Left = 559
    Top = 152
    Width = 297
    Height = 26
    Style = csDropDownList
    TabOrder = 4
  end
  object ComboUsuario: TComboBox
    Left = 559
    Top = 184
    Width = 297
    Height = 26
    Style = csDropDownList
    TabOrder = 5
  end
  object ComboCentro: TComboBox
    Left = 559
    Top = 216
    Width = 297
    Height = 26
    Style = csDropDownList
    TabOrder = 6
  end
  object ComboProjeto: TComboBox
    Left = 559
    Top = 248
    Width = 297
    Height = 26
    Style = csDropDownList
    TabOrder = 7
  end
  object ComboContabil: TComboBox
    Left = 559
    Top = 280
    Width = 297
    Height = 26
    Style = csDropDownList
    TabOrder = 8
  end
  object Button1: TButton
    Left = 261
    Top = 350
    Width = 436
    Height = 41
    Caption = 'SALVAR'
    Default = True
    TabOrder = 9
    OnClick = Button1Click
  end
  object PanelTopo: TPanel
    Left = 0
    Top = 0
    Width = 884
    Height = 97
    Align = alTop
    Color = 5395281
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGradientInactiveCaption
    Font.Height = 18
    Font.Name = 'Calibri'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 10
    object LabelCabecalhoTitulo: TLabel
      Left = 30
      Top = 13
      Width = 736
      Height = 40
      Caption = '[LINKAR] ELETROBIDU COMERCIAL ELETRICA LTDA ME'
      Color = clRed
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 3198613
      Font.Height = 40
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
    object LabelCabecalhoSubTitulo: TLabel
      Left = 30
      Top = 55
      Width = 221
      Height = 20
      Caption = 'MIP VENDAS <-----> MIP GEST'#195'O'
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 15790835
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
  end
  object Button2: TButton
    Left = 112
    Top = 288
    Width = 297
    Height = 25
    Caption = 'CARREGAR DADOS'
    TabOrder = 11
    OnClick = Button2Click
  end
  object SQLQuery1: TSQLQuery
    Params = <>
    Left = 568
    Top = 104
  end
  object SQLConnection1: TSQLConnection
    Left = 648
    Top = 104
  end
  object SQLQuery2: TSQLQuery
    Params = <>
    Left = 512
    Top = 104
  end
end
