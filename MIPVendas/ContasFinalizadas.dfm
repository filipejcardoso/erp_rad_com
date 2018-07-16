object FContasFinalizadas: TFContasFinalizadas
  Left = 0
  Top = 0
  Caption = 'Financeiro - Vendas Finalizadas'
  ClientHeight = 685
  ClientWidth = 1143
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 18
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 18
  object PanelPendentes: TPanel
    Left = 0
    Top = 129
    Width = 1143
    Height = 556
    Align = alClient
    Color = clMenuBar
    ParentBackground = False
    TabOrder = 0
    object PanelPendentesFixo: TPanel
      Left = 17
      Top = 20
      Width = 624
      Height = 435
      Color = clWhite
      ParentBackground = False
      TabOrder = 0
      object GridPendentes: TStringGrid
        Left = 1
        Top = 137
        Width = 622
        Height = 297
        Align = alClient
        TabOrder = 0
        OnDrawCell = GridPendentesDrawCell
        OnSelectCell = GridPendentesSelectCell
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
      object PanelPendentesFiltro: TPanel
        Left = 1
        Top = 1
        Width = 622
        Height = 136
        Align = alTop
        Color = 5395281
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGradientInactiveCaption
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 1
        object EditBuscaPendentes: TEdit
          Left = 22
          Top = 80
          Width = 435
          Height = 26
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = 18
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object ButtonFiltrarPendentes: TButton
          Left = 479
          Top = 80
          Width = 130
          Height = 25
          Caption = 'FILTRAR'
          Default = True
          TabOrder = 1
          OnClick = ButtonFiltrarPendentesClick
        end
        object GroupBox1: TGroupBox
          Left = 22
          Top = 9
          Width = 587
          Height = 58
          Caption = 'OP'#199#195'O DE CLIENTE'
          Color = cl3DDkShadow
          ParentBackground = False
          ParentColor = False
          TabOrder = 2
          object RadioSimplesPendentes: TRadioButton
            Left = 25
            Top = 27
            Width = 136
            Height = 17
            Caption = 'CLIENTE SIMPLES'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clSilver
            Font.Height = 18
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
          end
          object RadioIndicacaoPendentes: TRadioButton
            Left = 175
            Top = 27
            Width = 178
            Height = 17
            Caption = 'CLIENTE INDICA'#199#213'ES'
            Color = clSilver
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clSilver
            Font.Height = 18
            Font.Name = 'Calibri'
            Font.Style = []
            ParentColor = False
            ParentFont = False
            TabOrder = 1
          end
          object CheckConsumidorPendentes: TCheckBox
            Left = 354
            Top = 27
            Width = 111
            Height = 17
            Caption = 'CONSUMIDOR'
            TabOrder = 2
          end
        end
      end
    end
    object PanelPendentesVariavel: TPanel
      Left = 664
      Top = 20
      Width = 617
      Height = 434
      Color = clWhite
      ParentBackground = False
      TabOrder = 1
      object GridPendentesDetalhada: TStringGrid
        Left = 1
        Top = 113
        Width = 615
        Height = 320
        Align = alClient
        TabOrder = 0
        OnDrawCell = GridPendentesDetalhadaDrawCell
        OnSelectCell = GridPendentesDetalhadaSelectCell
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
      object Panel1: TPanel
        Left = 1
        Top = 1
        Width = 615
        Height = 112
        Align = alTop
        Color = 5395281
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGradientInactiveCaption
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 1
        object Label2: TLabel
          Left = 188
          Top = 22
          Width = 61
          Height = 18
          Caption = 'Data Final'
        end
        object Label3: TLabel
          Left = 24
          Top = 22
          Width = 68
          Height = 18
          Caption = 'Data Inicial'
        end
        object data_final: TDateTimePicker
          Left = 188
          Top = 46
          Width = 132
          Height = 31
          Date = 42235.857514675920000000
          Time = 42235.857514675920000000
          TabOrder = 0
        end
        object data_inicial: TDateTimePicker
          Left = 22
          Top = 46
          Width = 132
          Height = 31
          Date = 42217.857514675920000000
          Time = 42217.857514675920000000
          TabOrder = 1
        end
      end
    end
  end
  object PanelTopoPendentes: TPanel
    Left = 0
    Top = 0
    Width = 1143
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
    TabOrder = 1
    object LabelCabecalhoTitulo: TLabel
      Left = 40
      Top = 37
      Width = 936
      Height = 40
      Caption = '[VENDAS FINALIZADAS] ELETROBIDU COMERCIAL EL'#201'TRICA LTDA ME'
      Color = 432001
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
  object SQLQuery1: TSQLQuery
    Params = <>
    Left = 1071
    Top = 16
  end
end
