object FCaixa: TFCaixa
  Left = 0
  Top = 0
  Caption = 'Caixa'
  ClientHeight = 741
  ClientWidth = 1109
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 18
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 18
  object PanelTopo: TPanel
    Left = 0
    Top = 0
    Width = 1109
    Height = 129
    Align = alTop
    Color = 5395281
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGradientInactiveCaption
    Font.Height = 18
    Font.Name = 'Calibri'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 0
    object LabelCabecalhoTitulo: TLabel
      Left = 40
      Top = 37
      Width = 718
      Height = 40
      Caption = '[CAIXA] ELETROBIDU COMERCIAL ELETRICA LTDA ME'
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
      Left = 40
      Top = 83
      Width = 266
      Height = 20
      Caption = 'MIP VENDAS E CONTROLE DE ESTOQUE'
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
  object PanelVariavel: TPanel
    Left = 0
    Top = 129
    Width = 547
    Height = 612
    Align = alClient
    TabOrder = 1
    object PanelPagamento: TPanel
      Left = 24
      Top = 24
      Width = 521
      Height = 257
      Color = clWhite
      ParentBackground = False
      TabOrder = 0
      object StringGrid1: TStringGrid
        Left = 1
        Top = 1
        Width = 519
        Height = 255
        Align = alClient
        TabOrder = 0
        OnDrawCell = StringGrid1DrawCell
        OnSelectCell = StringGrid1SelectCell
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
    end
    object PanelDesconto: TPanel
      Left = 24
      Top = 296
      Width = 521
      Height = 346
      Color = clWhite
      ParentBackground = False
      TabOrder = 1
      object Label3: TLabel
        Left = 20
        Top = 32
        Width = 110
        Height = 18
        Caption = 'SALDO TOTAL (R$)'
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6974058
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object Label4: TLabel
        Left = 20
        Top = 144
        Width = 133
        Height = 18
        Caption = 'SALDO DINHEIRO (R$)'
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6974058
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object Label5: TLabel
        Left = 276
        Top = 144
        Width = 122
        Height = 18
        Caption = 'SALDO CART'#195'O (R$)'
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6974058
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object Label9: TLabel
        Left = 276
        Top = 248
        Width = 197
        Height = 18
        Caption = 'MOVIMENTA'#199#195'O CARTEIRA (R$)'
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6974058
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object Label10: TLabel
        Left = 20
        Top = 248
        Width = 122
        Height = 18
        Caption = 'SALDO CHEQUE (R$)'
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6974058
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object EditSaldoDinheiro: TEdit
        Left = 20
        Top = 168
        Width = 225
        Height = 48
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = 40
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object EditSaldoCartao: TEdit
        Left = 276
        Top = 168
        Width = 225
        Height = 48
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = 40
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object EditSaldoCarteira: TEdit
        Left = 276
        Top = 272
        Width = 225
        Height = 48
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = 40
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object EditSaldoCheque: TEdit
        Left = 20
        Top = 272
        Width = 225
        Height = 48
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = 40
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
      object EditSaldoTotal: TEdit
        Left = 20
        Top = 56
        Width = 481
        Height = 63
        Color = 5395281
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 3198613
        Font.Height = 55
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
        ReadOnly = True
        TabOrder = 4
      end
    end
  end
  object PanelFixo: TPanel
    Left = 547
    Top = 129
    Width = 562
    Height = 612
    Align = alRight
    TabOrder = 2
    object PanelProdutos: TPanel
      Left = 18
      Top = 24
      Width = 528
      Height = 401
      Color = clWhite
      ParentBackground = False
      TabOrder = 0
      object LabelCodigo: TLabel
        Left = 24
        Top = 24
        Width = 135
        Height = 30
        Caption = 'C'#243'digo: XXXX'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowFrame
        Font.Height = 30
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object LabelOperador: TLabel
        Left = 24
        Top = 72
        Width = 251
        Height = 30
        Caption = 'Operador: XXXXXXXXXX'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowFrame
        Font.Height = 30
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LabelData: TLabel
        Left = 24
        Top = 120
        Width = 184
        Height = 30
        Caption = 'Data: XX/XX/XXXX'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowFrame
        Font.Height = 30
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object LabelHorario: TLabel
        Left = 24
        Top = 168
        Width = 208
        Height = 30
        Caption = 'Hor'#225'rio: XX:XX:XXXX'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowFrame
        Font.Height = 30
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
    end
    object PanelFinalizar: TPanel
      Left = 19
      Top = 440
      Width = 526
      Height = 202
      Color = clWhite
      ParentBackground = False
      TabOrder = 1
      object LabelState: TLabel
        Left = 24
        Top = 10
        Width = 302
        Height = 60
        Caption = 'CAIXA ABERTO'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = 60
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ButtonAbrirFechar: TButton
        Left = 24
        Top = 75
        Width = 465
        Height = 51
        Caption = 'ABRIR CAIXA (F1)'
        TabOrder = 0
        OnClick = ButtonAbrirFecharClick
      end
      object ButtonLeituraX: TButton
        Left = 202
        Top = 139
        Width = 139
        Height = 37
        Caption = 'LEITURA X (F4)'
        TabOrder = 1
        OnClick = ButtonLeituraXClick
      end
      object ButtonReducaoZ: TButton
        Left = 357
        Top = 139
        Width = 132
        Height = 37
        Caption = 'REDU'#199#195'O Z (F5)'
        TabOrder = 2
        OnClick = ButtonReducaoZClick
      end
      object ButtonExtornar: TButton
        Left = 24
        Top = 139
        Width = 162
        Height = 37
        Caption = 'EXTORNAR VENDA (F3)'
        TabOrder = 3
        OnClick = ButtonExtornarClick
      end
    end
  end
  object SQLQuery1: TSQLQuery
    Params = <>
    Left = 440
    Top = 264
  end
  object ActionList1: TActionList
    Left = 440
    Top = 208
    object F1: TAction
      Caption = 'F1'
      ShortCut = 112
    end
    object F2: TAction
      Caption = 'F2'
      ShortCut = 113
    end
    object F3: TAction
      Caption = 'F3'
      ShortCut = 114
    end
    object F4: TAction
      Caption = 'F4'
      ShortCut = 115
    end
    object F5: TAction
      Caption = 'F5'
      ShortCut = 116
    end
    object F6: TAction
      Caption = 'F6'
      ShortCut = 117
    end
    object F7: TAction
      Caption = 'F7'
      ShortCut = 118
    end
    object F8: TAction
      Caption = 'F8'
      ShortCut = 119
    end
    object F12: TAction
      Caption = 'F12'
      ShortCut = 123
    end
  end
  object PrintDialog1: TPrintDialog
    Left = 368
    Top = 280
  end
  object SQLConnection1: TSQLConnection
    Left = 552
    Top = 376
  end
  object SQLQuery2: TSQLQuery
    Params = <>
    Left = 496
    Top = 272
  end
end
